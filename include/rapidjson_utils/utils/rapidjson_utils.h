#ifndef RAPIDJSON_UTILS_RAPIDJSON_UTILS_H
#define RAPIDJSON_UTILS_RAPIDJSON_UTILS_H

#include "./get_document.h"                    // IWYU pragma: export
#include "./get_json_string.h"                 // IWYU pragma: export
#include "./get_pretty_json_string.h"          // IWYU pragma: export
#include "./get_pretty_parse_error_message.h"  // IWYU pragma: export
#include "./merge_objects.h"                   // IWYU pragma: export

namespace rapidjson::utils::internal {

class RapidJsonUtilsClass {
public:
    const GetDocumentClass GetDocument{GetDocumentClass()};
    const GetJsonStringClass GetJsonString{GetJsonStringClass()};
    const GetPrettyJsonStringClass GetPrettyJsonString{GetPrettyJsonStringClass()};
    const GetPrettyParseErrorMessageClass GetPrettyParseErrorMessage{GetPrettyParseErrorMessageClass()};
    const MergeObjectsClass MergeObjects{MergeObjectsClass()};
};

}  // namespace rapidjson::utils::internal

static const auto RapidJsonUtils = rapidjson::utils::internal::RapidJsonUtilsClass();

#endif  // RAPIDJSON_UTILS_RAPIDJSON_UTILS_H