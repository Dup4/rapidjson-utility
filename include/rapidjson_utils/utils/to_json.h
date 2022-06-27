#ifndef RAPIDJSON_UTILS_UTILS_TO_JSON_H
#define RAPIDJSON_UTILS_UTILS_TO_JSON_H

namespace rapidjson::utils {

namespace internal {

class ToJsonStringClass {
public:
};

}  // namespace internal

static const auto ToJson = internal::ToJsonStringClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_UTILS_TO_JSON_H
