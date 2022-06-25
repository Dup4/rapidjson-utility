#ifndef RAPIDJSON_UTILS_INTERNAL_SCHEMA_PROPS_H
#define RAPIDJSON_UTILS_INTERNAL_SCHEMA_PROPS_H

#include <optional>
#include <string>
#include <string_view>

namespace rapidjson::utils {

template <typename T>
struct SchemaOptions {
    std::string key_name{""};
    std::optional<T> default_value{std::nullopt};
};

namespace internal {

class SchemaOptionsBuilderClass {
public:
    auto WithKeyName(std::string_view key_name) const {
        return [key_name](auto& options) {
            options.key_name = key_name;
        };
    }

    template <typename T>
    auto WithDefaultValue(T&& default_value) const {
        return [default_value = std::forward<T>(default_value)](auto& options) {
            options.default_value = default_value;
        };
    }

    template <typename T, typename... Opt>
    auto ApplySchemaOptions(SchemaOptions<T>& options, Opt&&... opts) const {
        (std::forward<Opt>(opts)(options), ...);
        return options;
    }

    template <typename T, typename... Opt>
    auto CreateSchemaOptions(Opt&&... opts) const {
        SchemaOptions<T> options;
        return ApplySchemaOptions(options, std::forward<Opt>(opts)...);
    }
};

}  // namespace internal

static const auto SchemaOptionsBuilder = internal::SchemaOptionsBuilderClass();

}  // namespace rapidjson::utils

#endif  //  RAPIDJSON_UTILS_INTERNAL_SCHEMA_PROPS_H
