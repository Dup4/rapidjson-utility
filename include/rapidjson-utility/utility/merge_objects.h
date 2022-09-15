#ifndef RAPIDJSON_UTILITY_UTILITY_MERGE_OBJECTS_H
#define RAPIDJSON_UTILITY_UTILITY_MERGE_OBJECTS_H

#include <string>

#include "rapidjson/document.h"

#include "../internal/result.h"
#include "./get_document.h"
#include "./get_json_string.h"

namespace rapidjson_utility {

namespace internal {

class MergeObjectsClass {
public:
    Result operator()(rapidjson::Value& dstObject,
                      rapidjson::Value& srcObject,
                      rapidjson::Document::AllocatorType& allocator) const {
        for (auto srcIt = srcObject.MemberBegin(); srcIt != srcObject.MemberEnd(); ++srcIt) {
            auto dstIt = dstObject.FindMember(srcIt->name);
            if (dstIt == dstObject.MemberEnd()) {
                rapidjson::Value dstName;
                rapidjson::Value dstVal;
                dstName.CopyFrom(srcIt->name, allocator);
                dstVal.CopyFrom(srcIt->value, allocator);

                dstObject.AddMember(dstName, dstVal, allocator);

                dstName.CopyFrom(srcIt->name, allocator);
                dstIt = dstObject.FindMember(dstName);
                if (dstIt == dstObject.MemberEnd()) {
                    auto res = Result::Builder(Result::ErrorCode::OtherError)
                                       .WithErrorMessage("append element failed")
                                       .Build();
                    RESULT_DIRECT_RETURN(res);
                }
            } else {
                auto srcT = srcIt->value.GetType();
                auto dstT = dstIt->value.GetType();
                if (srcT != dstT) {
                    auto res = Result::Builder(Result::ErrorCode::OtherError)
                                       .WithErrorMessage("srcType not equal to dstType")
                                       .Build();
                    RESULT_DIRECT_RETURN(res);
                }

                if (srcIt->value.IsArray()) {
                    for (const auto* arrayIt = srcIt->value.Begin(); arrayIt != srcIt->value.End(); ++arrayIt) {
                        rapidjson::Value dstVal;
                        dstVal.CopyFrom(*arrayIt, allocator);
                        dstIt->value.PushBack(dstVal, allocator);
                    }
                } else if (srcIt->value.IsObject()) {
                    RESULT_OK_OR_RETURN(this->operator()(dstIt->value, srcIt->value, allocator));
                } else {
                    dstIt->value.CopyFrom(srcIt->value, allocator);
                }
            }
        }

        return Result::OK();
    }

    ResultOr<std::string> operator()(std::string_view dst, std::string_view src) const {
        RESULT_VALUE_OR_RETURN(auto doc_dst, GetDocument(dst));
        RESULT_VALUE_OR_RETURN(auto doc_src, GetDocument(src));

        RESULT_OK_OR_RETURN(this->operator()(doc_dst, doc_src, doc_dst.GetAllocator()));

        return GetJsonString(doc_dst);
    }
};

}  // namespace internal

static const auto MergeObjects = internal::MergeObjectsClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_MERGE_OBJECTS_H
