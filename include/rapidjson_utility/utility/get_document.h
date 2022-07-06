#ifndef RAPIDJSON_UTILITY_UTILITY_GET_DOCUMENT_H
#define RAPIDJSON_UTILITY_UTILITY_GET_DOCUMENT_H

#include <string_view>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"

#include "../internal/result.h"
#include "./get_pretty_parse_error_message.h"

namespace rapidjson_utility {

namespace internal {

class GetDocumentClass {
public:
    ResultOr<rapidjson::Document> operator()(std::string_view json_string) const {
        rapidjson::Document doc;

        rapidjson::ParseResult err = doc.Parse(json_string.data());

        if (err.IsError()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(GetPrettyParseErrorMessage(err))
                    .Build();
        }

        return std::move(doc);
    }
};

}  // namespace internal

static const auto GetDocument = internal::GetDocumentClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_GET_DOCUMENT_H
