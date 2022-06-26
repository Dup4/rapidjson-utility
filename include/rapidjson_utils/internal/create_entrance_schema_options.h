#ifndef RAPIDJSON_UTILS_INTERNAL_CREATE_ENTRANCE_SCHEMA_OPTIONS_H
#define RAPIDJSON_UTILS_INTERNAL_CREATE_ENTRANCE_SCHEMA_OPTIONS_H

#include <string_view>
#include <type_traits>

#include "./result.h"
#include "./schema_options.h"

namespace rapidjson::utils {

namespace internal {

class CreateEntranceSchemaOptionsClass {
public:
    template <typename T, typename... Opt>
    auto operator()([[maybe_unused]] T* t, std::string_view field_name, Opt&&... opts) const {
        auto options = rapidjson::utils::SchemaOptions<T>{};
        options.key_name = field_name;
        SchemaOptionsBuilder.ApplySchemaOptions(options, std::forward<Opt>(opts)...);
        return options;
    }

    template <typename T, typename... Opt>
    auto operator()([[maybe_unused]] std::optional<T>* t, std::string_view field_name, Opt&&... opts) const {
        auto options = rapidjson::utils::SchemaOptions<T>{};
        options.key_name = field_name;
        SchemaOptionsBuilder.ApplySchemaOptions(options, std::forward<Opt>(opts)...);
        return options;
    }

    template <typename Struct, std::enable_if_t<std::is_const_v<Struct>, bool> = true, typename T, typename... Opt>
    auto operator()([[maybe_unused]] Struct* s, T* t, std::string_view field_name, Opt&&... opts) const {
        return operator()(static_cast<const T*>(t), field_name, std::forward<Opt>(opts)...);
    }

    template <typename Struct, std::enable_if_t<!std::is_const_v<Struct>, bool> = true, typename T, typename... Opt>
    auto operator()([[maybe_unused]] Struct* s, T* t, std::string_view field_name, Opt&&... opts) const {
        return operator()(s, t, field_name, std::forward<Opt>(opts)...);
    }
};

static const auto CreateEntranceSchemaOptions = internal::CreateEntranceSchemaOptionsClass();

}  // namespace internal

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_INTERNAL_CREATE_ENTRANCE_SCHEMA_OPTIONS_H
