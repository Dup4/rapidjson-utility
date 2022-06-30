#ifndef RAPIDJSON_UTILITY_TYPES_CHECK_HAS_RAPIDJSON_UTILITY_STRUCT_SCHEMA_ENTRANCE_H
#define RAPIDJSON_UTILITY_TYPES_CHECK_HAS_RAPIDJSON_UTILITY_STRUCT_SCHEMA_ENTRANCE_H

#include <type_traits>

#include "../internal/result.h"
#include "../internal/schema_options.h"

namespace rapidjson_utility {

namespace internal {

class FakeEntranceFunc {
public:
    template <typename T, typename F>
    Result operator()([[maybe_unused]] T* t, [[maybe_unused]] const F& options) const {
        return OKResult();
    }
};

}  // namespace internal

template <typename T>
class has_rapidjson_utility_struct_schema_entrance {
private:
    template <typename U>
    static constexpr auto check(int) -> decltype(U::__RapidJsonUtility_StructSchemaEntrance(std::declval<U*>(),
                                                         std::declval<internal::FakeEntranceFunc>()),
            std::true_type());

    template <typename>
    static constexpr std::false_type check(...);

    typedef decltype(check<T>(0)) type;

public:
    static constexpr bool value = type::value;
};

template <typename T>
inline constexpr bool has_rapidjson_utility_struct_schema_entrance_v =
        has_rapidjson_utility_struct_schema_entrance<T>::value;

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_TYPES_CHECK_HAS_RAPIDJSON_UTILITY_STRUCT_SCHEMA_ENTRANCE_H
