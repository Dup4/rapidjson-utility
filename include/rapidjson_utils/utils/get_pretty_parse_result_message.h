#ifndef RAPIDJSON_UTILS_GET_PRETTY_PARSE_RESULT_MESSAGE_H
#define RAPIDJSON_UTILS_GET_PRETTY_PARSE_RESULT_MESSAGE_H

#include <string>

#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"

namespace rapidjson::utils {

namespace internal {

class GetPrettyParseResultMessageClass {
public:
    std::string operator()(const ParseResult &parse_result) const {
        if (!parse_result.IsError()) {
            return GetParseError_En(parse_result.Code());
        }

        return std::string(GetParseError_En(parse_result.Code())) + " at offset " +
               std::to_string(parse_result.Offset());
    }
};

}  // namespace internal

static const auto GetPrettyParseResultMessage = internal::GetPrettyParseResultMessageClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_GET_PRETTY_PARSE_RESULT_MESSAGE_H
