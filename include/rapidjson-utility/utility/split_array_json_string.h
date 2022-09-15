#ifndef RAPIDJSON_UTILITY_UTILITY_SPLIT_ARRAY_JSON_STRING_H
#define RAPIDJSON_UTILITY_UTILITY_SPLIT_ARRAY_JSON_STRING_H

#include <string>
#include <string_view>
#include <vector>

#include "rapidjson/document.h"

#include "../internal/result.h"
#include "./get_document.h"
#include "./get_json_string.h"

namespace rapidjson_utility {

namespace internal {

class SplitArrayJsonStringClass {
public:
    ResultOr<std::vector<std::string>> operator()(std::string_view json_string) const {
        RESULT_VALUE_OR_RETURN(auto doc, GetDocument(json_string));

        if (!doc.IsArray()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage("this json string is not a array")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        std::vector<std::string> res{};
        for (const rapidjson::Value& item : doc.GetArray()) {
            res.push_back(GetJsonString(item));
        }

        return res;
    }
};

}  // namespace internal

static const auto SplitArrayJsonString = internal::SplitArrayJsonStringClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_SPLIT_ARRAY_JSON_STRING_H
