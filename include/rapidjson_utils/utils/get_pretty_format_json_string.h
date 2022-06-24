#ifndef RAPIDJSON_UTILS_GET_PRETTY_FORMAT_JSON_STRING_H
#define RAPIDJSON_UTILS_GET_PRETTY_FORMAT_JSON_STRING_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include "../internal/result.h"
#include "./get_pretty_parse_result_message.h"

namespace rapidjson::utils {

namespace internal {

class GetPrettyFormatJsonStringClass {
public:
    std::string operator()(const Document &doc) const {
        auto buffer = StringBuffer();
        auto pretty_writer = PrettyWriter<StringBuffer>(buffer);
        doc.Accept(pretty_writer);

        return std::string(buffer.GetString());
    }

    Result<std::string> operator()(const char *json_string) const {
        auto doc = Document();

        ParseResult err = doc.Parse(json_string);
        if (err.IsError()) {
            return Result<std::string>(ResultErrorCode::kParseError, GetPrettyParseResultMessage(err));
        }

        return operator()(doc);
    }

    Result<std::string> operator()(const std::string &json_string) const {
        return operator()(json_string.c_str());
    }
};

}  // namespace internal

static const auto GetPrettyFormatJsonString = internal::GetPrettyFormatJsonStringClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_GET_PRETTY_FORMAT_JSON_STRING_H
