#ifndef RAPIDJSON_UTILITY_UTILITY_MERGE_OBJECTS_H
#define RAPIDJSON_UTILITY_UTILITY_MERGE_OBJECTS_H

#include <string>

#include "rapidjson/document.h"

#include "../internal/result.h"
#include "../internal/result_or.h"
#include "./get_document.h"
#include "./get_json_string.h"

namespace rapidjson::utility {

namespace internal {

class MergeObjectsClass {
public:
    Result operator()(rapidjson::Value& dstObject, rapidjson::Value& srcObject,
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
                    return OtherErrorResult("append element failed");
                }
            } else {
                auto srcT = srcIt->value.GetType();
                auto dstT = dstIt->value.GetType();
                if (srcT != dstT) {
                    return OtherErrorResult("srcType not equal to dstType");
                }

                if (srcIt->value.IsArray()) {
                    for (const auto* arrayIt = srcIt->value.Begin(); arrayIt != srcIt->value.End(); ++arrayIt) {
                        rapidjson::Value dstVal;
                        dstVal.CopyFrom(*arrayIt, allocator);
                        dstIt->value.PushBack(dstVal, allocator);
                    }
                } else if (srcIt->value.IsObject()) {
                    auto res = operator()(dstIt->value, srcIt->value, allocator);
                    if (!res.IsOK()) {
                        return res;
                    }
                } else {
                    dstIt->value.CopyFrom(srcIt->value, allocator);
                }
            }
        }

        return OKResult();
    }

    ResultOr<std::string> operator()(std::string_view dst, std::string_view src) const {
        auto doc_dst = GetDocument(dst);
        if (!doc_dst.IsOK()) {
            return doc_dst;
        }

        auto doc_src = GetDocument(src);
        if (!doc_src.IsOK()) {
            return doc_src;
        }

        auto res = operator()(doc_dst.Value(), doc_src.Value(), doc_dst.Value().GetAllocator());
        if (!res.IsOK()) {
            return res;
        }

        return GetJsonString(doc_dst.Value());
    }
};

}  // namespace internal

static const auto MergeObjects = internal::MergeObjectsClass();

}  // namespace rapidjson::utility

#endif  // RAPIDJSON_UTILITY_UTILITY_MERGE_OBJECTS_H
