#ifndef RAPIDJSON_UTILITY_INTERNAL_SCHEMA_OPTIONS_H
#define RAPIDJSON_UTILITY_INTERNAL_SCHEMA_OPTIONS_H

#include <optional>
#include <string>
#include <string_view>

namespace rapidjson_utility {

namespace internal {

template <typename T>
struct SchemaOptionsStruct {
    std::string key_name{""};
    bool required{false};
    std::optional<T> default_value{std::nullopt};
};

}  // namespace internal

class SchemaOptions {
public:
    static auto WithKeyName(std::string_view key_name) {
        return [key_name](auto& options) {
            options.key_name = key_name;
        };
    }

    static auto WithRequired(bool required = true) {
        return [required](auto& options) {
            options.required = required;
        };
    }

    template <typename T>
    static auto WithDefaultValue(T&& default_value) {
        return [default_value = std::forward<T>(default_value)](auto& options) {
            options.default_value = default_value;
        };
    }

    template <typename T, typename... Opt>
    static auto ApplySchemaOptions(internal::SchemaOptionsStruct<T>& options, Opt&&... opts) {
        (std::forward<Opt>(opts)(options), ...);
        return options;
    }

    template <typename T, typename... Opt>
    static auto CreateSchemaOptions(Opt&&... opts) {
        internal::SchemaOptionsStruct<T> options;
        return ApplySchemaOptions(options, std::forward<Opt>(opts)...);
    }
};

}  // namespace rapidjson_utility

#endif  //  RAPIDJSON_UTILITY_INTERNAL_SCHEMA_OPTIONS_H
