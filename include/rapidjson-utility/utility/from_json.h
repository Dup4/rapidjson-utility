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

        RESULT_DIRECT_RETURN(res);
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, T* t) const {
        if (!doc.IsObject()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage("Document is not an object.")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        rapidjson::Value value = doc.GetObject();
        RESULT_DIRECT_RETURN(this->operator()(value, t));
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, std::vector<T>* target) const {
        if (!doc.IsArray()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage("Document is not an array.")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        for (rapidjson::Value& item : doc.GetArray()) {
            if (!item.IsObject()) {
                auto res = Result::Builder(Result::ErrorCode::ParseError)
                                   .WithErrorMessage("Array item is not an object.")
                                   .Build();
                RESULT_DIRECT_RETURN(res);
            }

            T target_instance = T{};
            RESULT_OK_OR_RETURN(this->operator()(item, &target_instance));

            target->push_back(target_instance);
        }

        return Result::OK();
    }

    template <typename T>
    Result operator()(rapidjson::Document& doc, std::map<std::string, T>* target) const {
        if (!doc.IsObject()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage("Document is not an object.")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        for (auto& member : doc.GetObject()) {
            if (!member.value.IsObject()) {
                auto res = Result::Builder(Result::ErrorCode::ParseError)
                                   .WithErrorMessage("Object member is not an object.")
                                   .Build();
                RESULT_DIRECT_RETURN(res);
            }

            T target_instance = T{};
            RESULT_OK_OR_RETURN(this->operator()(member.value, &target_instance));

            target->emplace(member.name.GetString(), std::move(target_instance));
        }

        return Result::OK();
    }

    template <typename T>
    Result operator()(std::string_view json_string, T* t) const {
        RESULT_VALUE_OR_RETURN(auto doc_res, GetDocument(json_string));
        RESULT_DIRECT_RETURN(operator()(doc_res, t));
    }

    template <typename T>
    ResultOr<T> New(std::string_view json_string) const {
        T t;
        RESULT_OK_OR_RETURN(operator()(json_string, &t));

        return t;
    }

private:
    template <typename T, std::enable_if_t<std::is_same_v<bool, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsBool()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected bool")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetBool();
        return Result::OK();
    }

    template <typename T, std::enable_if_t<std::is_same_v<float, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsFloat()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected float")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetFloat();
        return Result::OK();
    }

    template <typename T, std::enable_if_t<std::is_same_v<double, T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsDouble()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected double")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetDouble();
        return Result::OK();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<int, T> || std::is_same_v<int32_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsInt()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected int")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetInt();
        return Result::OK();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<unsigned int, T> || std::is_same_v<uint32_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsUint()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected uint32_t")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetUint();
        return Result::OK();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<long long, T> || std::is_same_v<int64_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsInt64()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected int64_t")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetInt64();
        return Result::OK();
    }

    template <typename T,
              std::enable_if_t<std::is_same_v<unsigned long long, T> || std::is_same_v<uint64_t, T>, bool> = true,
              typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsUint64()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected uint64_t")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = value.GetUint64();
        return Result::OK();
    }

    template <typename F>
    Result typeHandle(rapidjson::Value& value, std::string* target, const F& options) const {
        if (!value.IsString()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected std::string")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = std::string(value.GetString());
        return Result::OK();
    }

    template <typename T, std::enable_if_t<std::is_enum_v<T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsNumber()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected number")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        *target = static_cast<T>(value.GetInt());
        return Result::OK();
    }

    template <typename T, std::enable_if_t<!is_basic_type_v<T>, bool> = true, typename F>
    Result typeHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.IsObject()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected object")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        RESULT_DIRECT_RETURN(this->operator()(value, target));
    }

    template <typename T>
    Result typeHandle(rapidjson::Value& value,
                      std::vector<T>* target,
                      const internal::SchemaOptionsStruct<std::vector<T>>& options) const {
        if (!value.IsArray()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected array")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        for (rapidjson::Value& item : value.GetArray()) {
            T target_instance = T{};
            RESULT_OK_OR_RETURN(this->typeHandle(item, &target_instance, options));

            target->push_back(target_instance);
        }

        return Result::OK();
    }

    template <typename T>
    Result typeHandle(rapidjson::Value& value,
                      std::map<std::string, T>* target,
                      const internal::SchemaOptionsStruct<std::map<std::string, T>>& options) const {
        if (!value.IsObject()) {
            auto res = Result::Builder(Result::ErrorCode::ParseError)
                               .WithErrorMessage(options.key_name + " type invalid, expected object")
                               .Build();
            RESULT_DIRECT_RETURN(res);
        }

        for (auto& item : value.GetObject()) {
            T target_instance = T{};
            RESULT_OK_OR_RETURN(this->typeHandle(item.value, &target_instance, options));

            target->emplace(item.name.GetString(), std::move(target_instance));
        }

        return Result::OK();
    }

    template <typename T, typename F>
    Result objectHandle(rapidjson::Value& value, T* target, const F& options) const {
        if (!value.HasMember(options.key_name.c_str())) {
            if (options.default_value.has_value()) {
                *target = options.default_value.value();
                return Result::OK();
            } else if (options.required) {
                auto res = Result::Builder(Result::ErrorCode::ParseError)
                                   .WithErrorMessage(options.key_name + " not found")
                                   .Build();
                RESULT_DIRECT_RETURN(res);
            } else {
                return Result::OK();
            }
        }

        rapidjson::Value& sub_value = value[options.key_name.c_str()];
        RESULT_DIRECT_RETURN(this->typeHandle(sub_value, target, options));
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

            T target_instance = T{};
            RESULT_OK_OR_RETURN(this->typeHandle(sub_value, &target_instance, options));

            *target = target_instance;
        }

        return Result::OK();
    }
};

}  // namespace internal

static const auto FromJson = internal::FromJsonStringClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_FROM_JSON_H
