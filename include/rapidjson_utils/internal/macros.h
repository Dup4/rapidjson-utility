#ifndef RAPIDJSON_UTILS_INTERNAL_MACROS_H
#define RAPIDJSON_UTILS_INTERNAL_MACROS_H

#include <type_traits>

#include "../types_check/index.h"
#include "../utils/index.h"
#include "./create_entrance_schema_options.h"
#include "./result.h"
#include "./schema_options.h"

#define RAPIDJSON_UTILS_STR(x) #x

#define RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_BEGIN(Struct)                                                            \
private:                                                                                                               \
    friend class ::rapidjson::utils::has_rapidjson_utils_struct_schema_entrance<Struct>;                               \
    friend class ::rapidjson::utils::has_rapidjson_utils_struct_schema_entrance<const Struct>;                         \
    friend class ::rapidjson::utils::internal::StructInjectEntranceClass;                                              \
                                                                                                                       \
    template <typename T, std::enable_if_t<std::is_same_v<Struct, T> || std::is_same_v<const Struct, T>, bool> = true, \
            typename Func>                                                                                             \
    static auto __RapidJsonUtils_StructSchemaEntrance(T* s, Func&& func) {
//
#define RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(field, ...)                   \
    {                                                                             \
        auto options = ::rapidjson::utils::internal::CreateEntranceSchemaOptions( \
                &(s->field), RAPIDJSON_UTILS_STR(field), ##__VA_ARGS__);          \
        auto res = func(&(s->field), options);                                    \
        if (!res.IsOK()) {                                                        \
            return res;                                                           \
        }                                                                         \
    }

#define RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_END \
    return OKResult();                            \
    }

#define RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_BEGIN(Struct)                                                   \
    template <typename T, std::enable_if_t<std::is_same_v<Struct, T> || std::is_same_v<const Struct, T>, bool> = true, \
            typename Func>                                                                                             \
    static auto __RapidJsonUtilsExternal_StructSchemaEntrance(T* s, Func&& func) {
//
#define RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(field, ...) \
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(field, ##__VA_ARGS__)

#define RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_END \
    return OKResult();                                     \
    }

#endif  // RAPIDJSON_UTILS_INTERNAL_MACROS_H
