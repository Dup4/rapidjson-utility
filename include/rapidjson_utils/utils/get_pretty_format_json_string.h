#ifndef RAPIDJSON_UTILS_GET_PRETTY_FORMAT_JSON_STRING_H
#define RAPIDJSON_UTILS_GET_PRETTY_FORMAT_JSON_STRING_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

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

    std::tuple<ParseResult, std::string> operator()(const char *json_string) const {
        auto doc = Document();

        ParseResult err = doc.Parse(json_string);
        if (err.IsError()) {
            return std::make_tuple(err, "");
        }

        return std::make_tuple(err, operator()(doc));
    }

    std::tuple<ParseResult, std::string> operator()(const std::string &json_string) const {
        return operator()(json_string.c_str());
    }

    std::string Must(const char *json_string) const {
        auto [err, pretty_json_string] = operator()(json_string);
        return pretty_json_string;
    }

    std::string Must(const std::string &json_string) const {
        return Must(json_string.c_str());
    }
};

}  // namespace internal

static const auto GetPrettyFormatJsonString = internal::GetPrettyFormatJsonStringClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_GET_PRETTY_FORMAT_JSON_STRING_H
