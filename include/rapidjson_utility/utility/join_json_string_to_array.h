#ifndef RAPIDJSON_UTILITY_UTILITY_JOIN_JSON_STRING_TO_ARRAY_H
#define RAPIDJSON_UTILITY_UTILITY_JOIN_JSON_STRING_TO_ARRAY_H

#include <string>
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
        std::string json_string = "[";

        bool first = true;
        for (const auto& j : json_string_list) {
            if (!first) {
                json_string += ",";
            } else {
                first = false;
            }

            json_string += j;
        }

        json_string += "]";

        // prevent invalid json string
        RESULT_VALUE_OR_RETURN(auto doc, GetDocument(json_string));

        return GetJsonString(doc);
    }
};

}  // namespace internal

static const auto JoinJsonStringToArray = internal::JoinJsonStringToArrayClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_JOIN_JSON_STRING_TO_ARRAY_H
