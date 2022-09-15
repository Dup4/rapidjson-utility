#ifndef RAPIDJSON_UTILITY_UTILITY_GET_PRETTY_PARSE_ERROR_MESSAGE_H
#define RAPIDJSON_UTILITY_UTILITY_GET_PRETTY_PARSE_ERROR_MESSAGE_H

#include <string>

#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"

namespace rapidjson_utility {

namespace internal {

class GetPrettyParseErrorMessageClass {
public:
    std::string operator()(const rapidjson::ParseResult &parse_result) const {
        if (!parse_result.IsError()) {
            return GetParseError_En(parse_result.Code());
        }

        return std::string(GetParseError_En(parse_result.Code())) + " at offset " +
               std::to_string(parse_result.Offset());
    }
};

}  // namespace internal

static const auto GetPrettyParseErrorMessage = internal::GetPrettyParseErrorMessageClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_GET_PRETTY_PARSE_ERROR_MESSAGE_H
