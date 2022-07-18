#ifndef RAPIDJSON_UTILITY_UTILITY_GET_PRETTY_JSON_STRING_H
#define RAPIDJSON_UTILITY_UTILITY_GET_PRETTY_JSON_STRING_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include "../internal/result.h"
#include "./get_document.h"
#include "./get_pretty_parse_error_message.h"

namespace rapidjson_utility {

namespace internal {

class GetPrettyJsonStringClass {
public:
    std::string operator()(const rapidjson::Document &doc) const {
        auto buffer = rapidjson::StringBuffer();
        auto pretty_writer = rapidjson::PrettyWriter<rapidjson::StringBuffer>(buffer);

        doc.Accept(pretty_writer);

        return std::string(buffer.GetString());
    }

    ResultOr<std::string> operator()(std::string_view json_string) const {
        RESULT_VALUE_OR_RETURN(auto doc, GetDocument(json_string));
        return this->operator()(doc);
    }
};

}  // namespace internal

static const auto GetPrettyJsonString = internal::GetPrettyJsonStringClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_GET_PRETTY_JSON_STRING_H
