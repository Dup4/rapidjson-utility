#ifndef RAPIDJSON_UTILS_TYPES_CHECK_IS_BASIC_TYPE_H
#define RAPIDJSON_UTILS_TYPES_CHECK_IS_BASIC_TYPE_H

#include <string>
#include <type_traits>

namespace rapidjson::utils {

template <typename T>
inline constexpr bool is_basic_type_v =
        std::is_same_v<int, T> || std::is_same_v<unsigned int, T> || std::is_same_v<int32_t, T> ||
        std::is_same_v<uint32_t, T> || std::is_same_v<long long, T> || std::is_same_v<unsigned long long, T> ||
        std::is_same_v<int64_t, T> || std::is_same_v<uint64_t, T> || std::is_same_v<float, T> ||
        std::is_same_v<double, T> || std::is_same_v<bool, T> || std::is_same_v<std::string, T>;

}

#endif  // RAPIDJSON_UTILS_TYPES_CHECK_IS_BASIC_TYPE_H
