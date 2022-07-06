#ifndef RAPIDJSON_UTILITY_UTILITY_FROM_JSON_H
#define RAPIDJSON_UTILITY_UTILITY_FROM_JSON_H

#include <cstdint>
#include <optional>
#include <string_view>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"

#include "../internal/overload.h"
#include "../internal/result.h"
#include "../internal/schema_options.h"
#include "../internal/struct_inject_entrance.h"
#include "../types_check/index.h"
#include "../types_check/is_basic_type.h"
#include "./get_document.h"
#include "./get_pretty_parse_error_message.h"

namespace rapidjson_utility {

namespace internal {

class FromJsonStringClass {
public:
    template <typename T>
    Result operator()(rapidjson::Value& value, T* t) const {
        auto res = StructInjectEntrance(t, [&value, this](auto&& t, auto&& options) {
            return this->objectHandle(value, t, options);
        });

        return res;
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, T* t) const {
        if (!doc.IsObject()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage("Document is not an object.")
                    .Build();
        }

        rapidjson::Value value = doc.GetObject();
        return operator()(value, t);
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, std::vector<T>* target) const {
        if (!doc.IsArray()) {
            return Result::Builder(Result::ErrorCode::ParseError).WithErrorMessage("Document is not an array.").Build();
        }

        for (rapidjson::Value& item : doc.GetArray()) {
            if (!item.IsObject()) {
                return Result::Builder(Result::ErrorCode::ParseError)
                        .WithErrorMessage("Array item is not an object.")
                        .Build();
            }

            T target_instance;

            auto res = this->operator()(item, &target_instance);
            if (!res.IsOK()) {
                return res;
            }

            target->push_back(target_instance);
        }

        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, std::map<std::string, T>* target) const {
        if (!doc.IsObject()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage("Document is not an object.")
                    .Build();
        }

        for (auto& member : doc.GetObject()) {
            if (!member.value.IsObject()) {
                return Result::Builder(Result::ErrorCode::ParseError)
                        .WithErrorMessage("Object member is not an object.")
                        .Build();
            }

            T target_instance;

            auto res = this->operator()(member.value, &target_instance);
            if (!res.IsOK()) {
                return res;
            }

            target->emplace(member.name.GetString(), std::move(target_instance));
        }

        return Result::Builder(Result::ErrorCode::OK).Build();
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
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected bool")
                    .Build();
        }

        *target = value.GetBool();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T, std::enable_if_t<std::is_same_v<float, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsFloat()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected float")
                    .Build();
        }

        *target = value.GetFloat();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T, std::enable_if_t<std::is_same_v<double, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsDouble()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected double")
                    .Build();
        }

        *target = value.GetDouble();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<int, T> || std::is_same_v<int32_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsInt()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected int")
                    .Build();
        }

        *target = value.GetInt();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<unsigned int, T> || std::is_same_v<uint32_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsUint()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected uint32_t")
                    .Build();
        }

        *target = value.GetUint();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<long long, T> || std::is_same_v<int64_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsInt64()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected int64_t")
                    .Build();
        }

        *target = value.GetInt64();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<unsigned long long, T> || std::is_same_v<uint64_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsUint64()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected uint64_t")
                    .Build();
        }

        *target = value.GetUint64();
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename F>
    Result typeHandle(rapidjson::Value& value, std::string* target, const F& options) const {
        if (!value.IsString()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected std::string")
                    .Build();
        }

        *target = std::string(value.GetString());
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T, std::enable_if_t<std::is_enum_v<T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsNumber()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected number")
                    .Build();
        }

        *target = static_cast<T>(value.GetInt());
        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T, std::enable_if_t<!is_basic_type_v<T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsObject()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected object")
                    .Build();
        }

        return this->operator()(value, target);
    }

    template <typename T>
    Result typeHandle(rapidjson::Value& value,
                      std::vector<T>* target,
                      const internal::SchemaOptionsStruct<std::vector<T>>& options) const {
        if (!value.IsArray()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected array")
                    .Build();
        }

        for (rapidjson::Value& item : value.GetArray()) {
            T target_instance;

            auto res = this->typeHandle(item, &target_instance, options);
            if (!res.IsOK()) {
                return res;
            }

            target->push_back(target_instance);
        }

        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T>
    Result typeHandle(rapidjson::Value& value,
                      std::map<std::string, T>* target,
                      const internal::SchemaOptionsStruct<std::map<std::string, T>>& options) const {
        if (!value.IsObject()) {
            return Result::Builder(Result::ErrorCode::ParseError)
                    .WithErrorMessage(options.key_name + " type invalid, expected object")
                    .Build();
        }

        for (auto& item : value.GetObject()) {
            T target_instance;

            auto res = this->typeHandle(item.value, &target_instance, options);
            if (!res.IsOK()) {
                return res;
            }

            target->emplace(item.name.GetString(), std::move(target_instance));
        }

        return Result::Builder(Result::ErrorCode::OK).Build();
    }

    template <typename T, typename F>
    Result objectHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.HasMember(options.key_name.c_str())) {
            if (options.default_value.has_value()) {
                *target = options.default_value.value();
                return Result::Builder(Result::ErrorCode::OK).Build();
            } else if (options.required) {
                return Result::Builder(Result::ErrorCode::ParseError)
                        .WithErrorMessage(options.key_name + " not found")
                        .Build();
            } else {
                return Result::Builder(Result::ErrorCode::OK).Build();
            }
        }

        rapidjson::Value& sub_value = value[options.key_name.c_str()];
        return this->typeHandle(sub_value, target, options);
    }

    template <typename T>
    Result objectHandle(rapidjson::Value& value,
                        std::optional<T>* target,
                        const internal::SchemaOptionsStruct<T>& options) const {
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

        return Result::Builder(Result::ErrorCode::OK).Build();
    }
};

}  // namespace internal

static const auto FromJson = internal::FromJsonStringClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_FROM_JSON_H
