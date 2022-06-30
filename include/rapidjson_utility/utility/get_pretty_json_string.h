#ifndef RAPIDJSON_UTILITY_UTILS_GET_PRETTY_JSON_STRING_H
#define RAPIDJSON_UTILITY_UTILS_GET_PRETTY_JSON_STRING_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"

#include "../internal/result_or.h"
#include "./get_document.h"
#include "./get_pretty_parse_error_message.h"

namespace rapidjson::utility {

namespace internal {

class GetPrettyJsonStringClass {
public:
    std::string operator()(const Document &doc) const {
        auto buffer = StringBuffer();
        auto pretty_writer = PrettyWriter<StringBuffer>(buffer);

        doc.Accept(pretty_writer);

        return std::string(buffer.GetString());
    }

    ResultOr<std::string> operator()(std::string_view json_string) const {
        auto doc_res = GetDocument(json_string);
        if (!doc_res.IsOK()) {
            return doc_res;
        }

        return operator()(doc_res.Value());
    }
};

}  // namespace internal

static const auto GetPrettyJsonString = internal::GetPrettyJsonStringClass();

}  // namespace rapidjson::utility

#endif  // RAPIDJSON_UTILITY_UTILS_GET_PRETTY_JSON_STRING_H
