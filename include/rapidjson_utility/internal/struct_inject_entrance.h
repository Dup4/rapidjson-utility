#ifndef RAPIDJSON_UTILITY_INTERNAL_STRUCT_INJECT_ENTRANCE_H
#define RAPIDJSON_UTILITY_INTERNAL_STRUCT_INJECT_ENTRANCE_H

#include "../types_check/common.h"
#include "../types_check/has_rapidjson_utility_external_struct_schema_entrance.h"
#include "../types_check/has_rapidjson_utility_struct_schema_entrance.h"
#include "./result.h"

namespace rapidjson_utility::internal {

class StructInjectEntranceClass {
public:
    template <typename T, typename Func>
    Result operator()(T* t, Func&& func) const {
        if constexpr (has_rapidjson_utility_struct_schema_entrance_v<T>) {
            return T::__RapidJsonUtility_StructSchemaEntrance(t, func);
        } else if constexpr (has_rapidjson_utility_external_struct_schema_entrance_v<T>) {
            return __RapidJsonUtilityExternal_StructSchemaEntrance(t, func);
        } else {
            static_assert(
                    false_v<T>,
                    "T does not have T::__RapidJsonUtility_StructSchemaEntrance() member function or __RapidJsonUtilityExternal_StructSchemaEntrance() external function");
        }
    }
};

static const auto StructInjectEntrance = StructInjectEntranceClass();

}  // namespace rapidjson_utility::internal

#endif  // RAPIDJSON_UTILITY_INTERNAL_STRUCT_INJECT_ENTRANCE_H
