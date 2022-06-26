#ifndef RAPIDJSON_UTILS_TYPES_CHECK_HAS_RAPIDJSON_UTILS_STRUCT_SCHEMA_ENTRANCE_H
#define RAPIDJSON_UTILS_TYPES_CHECK_HAS_RAPIDJSON_UTILS_STRUCT_SCHEMA_ENTRANCE_H

#include <type_traits>

#include "../internal/result.h"
#include "../internal/schema_options.h"

namespace rapidjson::utils {

class FakeEntranceFunc {
public:
    template <typename T>
    Result operator()([[maybe_unused]] T* t, [[maybe_unused]] const SchemaOptions<T>& options) const {
        return OKResult();
    }
};

template <typename T>
class has_rapidjson_utils_struct_schema_entrance {
private:
    template <typename U>
    static constexpr auto check(int)
            -> decltype(U::__RapidJsonUtils_StructSchemaEntrance(std::declval<U*>(), std::declval<FakeEntranceFunc>()),
                    std::true_type());

    template <typename>
    static constexpr std::false_type check(...);

    typedef decltype(check<T>(0)) type;

public:
    static constexpr bool value = type::value;
};

template <typename T>
inline constexpr bool has_rapidjson_utils_struct_schema_entrance_v =
        has_rapidjson_utils_struct_schema_entrance<T>::value;

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_TYPES_CHECK_HAS_RAPIDJSON_UTILS_STRUCT_SCHEMA_ENTRANCE_H
