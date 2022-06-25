#ifndef RAPIDJSON_UTILS_INTERNAL_MACROS_H
#define RAPIDJSON_UTILS_INTERNAL_MACROS_H

#include <type_traits>

#include "../types_check/index.h"
#include "./schema_options.h"

#define RAPIDJSON_UTILS_STR(x) #x

#define RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_BEGIN(Struct)                                                            \
private:                                                                                                               \
    friend class ::rapidjson::utils::has_rapidjson_utils_struct_schema_entrance<Struct>;                               \
    friend class ::rapidjson::utils::has_rapidjson_utils_struct_schema_entrance<const Struct>;                         \
                                                                                                                       \
    template <typename T, std::enable_if_t<std::is_same_v<Struct, T> || std::is_same_v<const Struct, T>, bool> = true, \
            typename Func>                                                                                             \
    static void __RapidJsonUtils_StructSchemaEntrance(T* s, Func&& func) {                                             \
        using _Struct = Struct;

#define RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(field, ...)              \
    {                                                                        \
        if constexpr (std::is_const_v(_Struct)) {                            \
            using field_type = const std::decay_t<decltype(s->field)>;       \
                                                                             \
            auto options = ::rapidjson::utils::SchemaOptions<field_type>();  \
            options.key = RAPIDJSON_UTILS_STR(field);                        \
            SchemaOptionsBuilder.ApplySchemaOptions(options, ##__VA_ARGS__); \
                                                                             \
            func(&(s->field), options);                                      \
        } else {                                                             \
            using field_type = std::decay_t<decltype(s->field)>;             \
                                                                             \
            auto options = ::rapidjson::utils::SchemaOptions<field_type>();  \
            options.key = RAPIDJSON_UTILS_STR(field);                        \
            SchemaOptionsBuilder.ApplySchemaOptions(options, ##__VA_ARGS__); \
                                                                             \
            func(&(s->field), options);                                      \
        }                                                                    \
    }

#define RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_END }

#define RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_BEGIN(Struct)                                                   \
    template <typename T, std::enable_if_t<std::is_same_v<Struct, T> || std::is_same_v<const Struct, T>, bool> = true, \
            typename Func>                                                                                             \
    static void __RapidJsonUtilsExternal_StructSchemaEntrance(T* s, Func&& func) {                                     \
        using _Struct = Struct;

#define RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(field, ...) \
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(field, ##__VA_ARGS__)

#define RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_END }

#endif  // RAPIDJSON_UTILS_INTERNAL_MACROS_H
