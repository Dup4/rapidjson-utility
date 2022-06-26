#ifndef RAPIDJSON_UTILS_UTILS_FROM_JSON_H
#define RAPIDJSON_UTILS_UTILS_FROM_JSON_H

#include <cstdint>
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
#include "../types_check/is_basic_type.h"
#include "./get_document.h"
#include "./get_pretty_parse_error_message.h"

namespace rapidjson::utils {

namespace internal {

class FromJsonStringClass {
public:
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
    Result operator()(rapidjson::Document& doc, std::vector<T>* target) const {
        if (!doc.IsArray()) {
            return ParseErrorResult("Document is not an array.");
        }

        for (rapidjson::Value& item : doc.GetArray()) {
            if (!item.IsObject()) {
                return ParseErrorResult("Array item is not an object.");
            }

            T target_instance;

            auto res = this->operator()(item, &target_instance);
            if (!res.IsOK()) {
                return res;
            }

            target->push_back(target_instance);
        }

        return OKResult();
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
    ResultOr<T> New(std::string_view json_string) const {
        T t;

        auto res = operator()(json_string, &t);
        if (!res.IsOK()) {
            return res;
        }

        return t;
    }

private:
    template <typename T, std::enable_if_t<std::is_same_v<bool, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsBool()) {
            return ParseErrorResult(options.key_name + " type invalid, expected bool");
        }

        *target = value.GetBool();
        return OKResult();
    }

    template <typename T, std::enable_if_t<std::is_same_v<float, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsFloat()) {
            return ParseErrorResult(options.key_name + " type invalid, expected float");
        }

        *target = value.GetFloat();
        return OKResult();
    }

    template <typename T, std::enable_if_t<std::is_same_v<double, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsDouble()) {
            return ParseErrorResult(options.key_name + " type invalid, expected double");
        }

        *target = value.GetDouble();
        return OKResult();
    }

    template <typename T, std::enable_if_t<std::is_same_v<int, T> || std::is_same_v<int32_t, T>, bool> = true,
            typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsInt()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: int32_t");
        }

        *target = value.GetInt();
        return OKResult();
    }

    template <typename T, std::enable_if_t<std::is_same_v<unsigned int, T> || std::is_same_v<uint32_t, T>, bool> = true,
            typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsUint()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: uint32_t");
        }

        *target = value.GetUint();
        return OKResult();
    }

    template <typename T, std::enable_if_t<std::is_same_v<long long, T> || std::is_same_v<int64_t, T>, bool> = true,
            typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsInt64()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: int64_t");
        }

        *target = value.GetInt64();
        return OKResult();
    }

    template <typename T,
            std::enable_if_t<std::is_same_v<unsigned long long, T> || std::is_same_v<uint64_t, T>, bool> = true,
            typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsUint64()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: uint64_t");
        }

        *target = value.GetUint64();
        return OKResult();
    }

    template <typename F>
    Result typeHandle(rapidjson::Value& value, std::string* target, const F& options) const {
        if (!value.IsString()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: string");
        }

        *target = std::string(value.GetString());
        return OKResult();
    }

    template <typename T, std::enable_if_t<!is_basic_type_v<T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsObject()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: object");
        }

        return this->operator()(value, target);
    }

    template <typename T>
    Result typeHandle(
            rapidjson::Value& value, std::vector<T>* target, const SchemaOptions<std::vector<T>>& options) const {
        if (!value.IsArray()) {
            return ParseErrorResult(options.key_name + " type invalid, expected: array");
        }

        for (rapidjson::Value& item : value.GetArray()) {
            T target_instance;

            auto res = this->typeHandle(item, &target_instance, options);
            if (!res.IsOK()) {
                return res;
            }

            target->push_back(target_instance);
        }

        return OKResult();
    }

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
        return this->typeHandle(sub_value, target, options);
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
            auto res = this->typeHandle(sub_value, &target_instance, options);
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
