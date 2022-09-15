#ifndef RAPIDJSON_UTILITY_UTILITY_JOIN_JSON_STRING_TO_ARRAY_H
#define RAPIDJSON_UTILITY_UTILITY_JOIN_JSON_STRING_TO_ARRAY_H

#include <string>
#include <string_view>
#include <vector>

#include "rapidjson/document.h"

#include "../internal/result.h"
#include "./get_document.h"
#include "./get_json_string.h"

namespace rapidjson_utility {

namespace internal {

class JoinJsonStringToArrayClass {
public:
    ResultOr<std::string> operator()(const std::vector<std::string>& json_string_list) const {
        rapidjson::Document doc;
        doc.SetArray();

        for (const auto& j : json_string_list) {
            RESULT_VALUE_OR_RETURN(auto sub_doc, GetDocument(j));
            doc.PushBack(sub_doc, doc.GetAllocator());
        }

        return GetJsonString(doc);
    }
};

}  // namespace internal

static const auto JoinJsonStringToArray = internal::JoinJsonStringToArrayClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_JOIN_JSON_STRING_TO_ARRAY_H
