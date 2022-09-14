#ifndef RAPIDJSON_UTILITY_UTILITY_RAPIDJSON_UTILITY_H
#define RAPIDJSON_UTILITY_UTILITY_RAPIDJSON_UTILITY_H

#include "./from_json.h"                       // IWYU pragma: export
#include "./get_document.h"                    // IWYU pragma: export
#include "./get_json_string.h"                 // IWYU pragma: export
#include "./get_pretty_json_string.h"          // IWYU pragma: export
#include "./get_pretty_parse_error_message.h"  // IWYU pragma: export
#include "./merge_objects.h"                   // IWYU pragma: export
#include "./split_array_json_string.h"         //  IWYU pragma: export
#include "./to_json.h"                         // IWYU pragma: export

namespace rapidjson_utility::internal {

class RapidJsonUtilityClass {
public:
    const FromJsonStringClass FromJson{FromJsonStringClass()};
    const ToJsonStringClass ToJson{ToJsonStringClass()};
    const GetDocumentClass GetDocument{GetDocumentClass()};
    const GetJsonStringClass GetJsonString{GetJsonStringClass()};
    const GetPrettyJsonStringClass GetPrettyJsonString{GetPrettyJsonStringClass()};
    const GetPrettyParseErrorMessageClass GetPrettyParseErrorMessage{GetPrettyParseErrorMessageClass()};
    const MergeObjectsClass MergeObjects{MergeObjectsClass()};
    const SplitArrayJsonStringClass SplitArrayJsonString{SplitArrayJsonStringClass()};
};

}  // namespace rapidjson_utility::internal

static const auto RapidJsonUtility = rapidjson_utility::internal::RapidJsonUtilityClass();

#endif  // RAPIDJSON_UTILITY_UTILITY_RAPIDJSON_UTILITY_H
