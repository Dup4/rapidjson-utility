#ifndef RAPIDJSON_UTILS_UTILS_FROM_JSON_H
#define RAPIDJSON_UTILS_UTILS_FROM_JSON_H

#include <optional>
#include <string_view>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"

#include "../internal/overload.h"
#include "../internal/result.h"
#include "../internal/result_or.h"
#include "../internal/schema_options.h"
#include "../types_check/index.h"
#include "./get_document.h"
#include "./get_pretty_parse_error_message.h"
#include "rapidjson_utils/types_check/is_basic_type.h"

namespace rapidjson::utils {

namespace internal {

class FromJsonStringClass {
public:
    template <typename T, std::enable_if_t<is_basic_type_v<T>, bool> = true, typename F>
    Result operator()(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.Is<T>()) {
            return ParseErrorResult(options.key_name + " type invalid");
        }

        *target = value.Get<T>();
        return OKResult();
    }

    template <typename T, std::enable_if_t<!is_basic_type_v<T>, bool> = true, typename F>
    Result operator()(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsObject()) {
            return ParseErrorResult(options.key_name + " type invalid");
        }

        *target = operator()(value, target);
        return OKResult();
    }

    template <typename F>
    Result operator()(rapidjson::Value& value, std::string* target, const F& options) const {
        if (!value.IsString()) {
            return ParseErrorResult(options.key_name + " type invalid");
        }

        *target = std::string(value.GetString());
        return OKResult();
    }

    template <typename T>
    Result operator()(
            rapidjson::Value& value, std::vector<T>* target, const SchemaOptions<std::vector<T>>& options) const {
        if (!value.IsArray()) {
            return ParseErrorResult(options.key_name + " type invalid");
        }

        for (rapidjson::Value& item : value.GetArray()) {
            T target_instance;

            auto res = this->operator()(item, &target_instance, options);
            if (!res.IsOK()) {
                return res;
            }

            target->push_back(target_instance);
        }

        return OKResult();
    }

    template <typename T>
    Result operator()(rapidjson::Value& value, T* t) const {
        auto res = entrance(t, [&value, this](auto&& t, auto&& options) {
            return this->objectHandle(value, t, options);
        });

        return res;
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, T* t) const {
        if (!doc.IsObject()) {
            return ParseErrorResult("Document is not an object.");
        }

        rapidjson::Value value = doc.GetObject();
        return operator()(value, t);
    }

    template <typename T>
    Result operator()(std::string_view json_string, T* t) const {
        auto doc_res = GetDocument(json_string);
        if (!doc_res.IsOK()) {
            return doc_res;
        }

        return operator()(doc_res.Value(), t);
    }

    template <typename T>
    ResultOr<T> operator()(std::string_view json_string) const {
        T t;

        auto res = operator()(json_string, &t);
        if (!res.IsOK()) {
            return res;
        }

        return t;
    }

private:
    template <typename T, typename F>
    Result objectHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.HasMember(options.key_name.c_str())) {
            if (options.default_value.has_value()) {
                *target = options.default_value.value();
                return OKResult();
            } else {
                return MemberNotFoundErrorResult(options.key_name + " not found");
            }
        }

        rapidjson::Value& sub_value = value[options.key_name.c_str()];
        return this->operator()(sub_value, target, options);
    }

    template <typename T>
    Result objectHandle(rapidjson::Value& value, std::optional<T>* target, const SchemaOptions<T>& options) const {
        if (!value.HasMember(options.key_name.c_str())) {
            if (options.default_value.has_value()) {
                *target = options.default_value.value();
            }
        } else {
            rapidjson::Value& sub_value = value[options.key_name.c_str()];
            T target_instance;
            auto res = this->operator()(sub_value, &target_instance, options);
            if (!res.IsOK()) {
                return res;
            }

            *target = options.default_value;
        }

        return OKResult();
    }

    template <typename T, typename Func>
    Result entrance(T* t, Func&& func) const {
        if constexpr (has_rapidjson_utils_struct_schema_entrance_v<T>) {
            return T::__RapidJsonUtils_StructSchemaEntrance(t, func);
        } else if constexpr (has_rapidjson_utils_external_struct_schema_entrance_v<T>) {
            return __RapidJsonUtilsExternal_StructSchemaEntrance(t, func);
        } else {
            static_assert(false_v<T>,
                    "T does not have T::__RapidJsonUtils_StructSchemaEntrance() member function or __RapidJsonUtilsExternal_StructSchemaEntrance() external function");
        }
    }
};

}  // namespace internal

static const auto FromJson = internal::FromJsonStringClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_UTILS_FROM_JSON_H
