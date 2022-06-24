#ifndef RAPIDJSON_UTILS_GET_DOCUMENT_H
#define RAPIDJSON_UTILS_GET_DOCUMENT_H

#include <string_view>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"

#include "../internal/result_or.h"
#include "./get_pretty_parse_error_message.h"

namespace rapidjson::utils {

namespace internal {

class GetDocumentClass {
public:
    ResultOr<Document> operator()(std::string_view json_string) const {
        Document doc;

        ParseResult err = doc.Parse(json_string.data());

        if (err.IsError()) {
            return ParseErrorResult(GetPrettyParseErrorMessage(err));
        }

        return std::move(doc);
    }
};

}  // namespace internal

static const auto GetDocument = internal::GetDocumentClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_GET_DOCUMENT_H
