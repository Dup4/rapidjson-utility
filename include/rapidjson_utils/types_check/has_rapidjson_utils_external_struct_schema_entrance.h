#ifndef RAPIDJSON_UTILS_TYPES_CHECK_HAS_RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_ENTRANCE_H
#define RAPIDJSON_UTILS_TYPES_CHECK_HAS_RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_ENTRANCE_H

#include <type_traits>

#include "./has_rapidjson_utils_struct_schema_entrance.h"

namespace rapidjson::utils {

template <typename T>
class has_rapidjson_utils_external_struct_schema_entrance {
private:
    template <typename U>
    static constexpr auto check(int) -> decltype(__RapidJsonUtilsExternal_StructSchemaEntrance(std::declval<U*>(),
                                                         std::declval<internal::FakeEntranceFunc>()),
            std::true_type());

    template <typename>
    static constexpr std::false_type check(...);

    typedef decltype(check<T>(0)) type;

public:
    static constexpr bool value = type::value;
};

template <typename T>
inline constexpr bool has_rapidjson_utils_external_struct_schema_entrance_v =
        has_rapidjson_utils_external_struct_schema_entrance<T>::value;

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_TYPES_CHECK_HAS_RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_ENTRANCE_H
