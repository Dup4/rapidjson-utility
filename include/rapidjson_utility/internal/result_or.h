#ifndef RAPIDJSON_UTILITY_INTERNAL_RESULT_OR_H
#define RAPIDJSON_UTILITY_INTERNAL_RESULT_OR_H

#include <optional>
#include <type_traits>

#include "./result.h"

namespace rapidjson_utility {

template <typename T>
class ResultOr : public Result {
public:
    ResultOr() = default;

    ResultOr(T&& value) : value_(std::move(value)) {}

    ResultOr(Result&& result) : Result(result) {}

    ResultOr(const ResultOr<T>& other) : Result(other), value_(other.value_) {}

    template <typename F, std::enable_if_t<!std::is_same_v<F, T>, bool> = true>
    ResultOr(const ResultOr<F>& other) : Result(other) {}

    ResultOr(ResultOr<T>&& other) : Result(other), value_(std::move(other.value_)) {}

    template <typename F, std::enable_if_t<!std::is_same_v<F, T>, bool> = true>
    ResultOr(ResultOr<F>&& other) : Result(other) {}

    ResultOr<T>& operator=(const ResultOr<T>& other) {
        Result::operator=(other);
        value_ = other.value_;
        return *this;
    }

    template <typename F, std::enable_if_t<!std::is_same_v<F, T>, bool> = true>
    ResultOr<T>& operator=(const ResultOr<F>& other) {
        Result::operator=(other);
        return *this;
    }

    ResultOr<T>& operator=(ResultOr<T>&& other) {
        Result::operator=(other);
        value_ = std::move(other.value_);
        return *this;
    }

    template <typename F, std::enable_if_t<!std::is_same_v<F, T>, bool> = true>
    ResultOr<T>& operator=(ResultOr<F>&& other) {
        Result::operator=(other);
        return *this;
    }

    const T& Value() const& {
        return *value_;
    }

    T& Value() & {
        return *value_;
    }

    const T&& Value() const&& {
        return std::move(*value_);
    }

    T&& Value() && {
        return std::move(*value_);
    }

    const T& operator*() const& {
        return *value_;
    }

    T& operator*() & {
        return *value_;
    }

    const T&& operator*() const&& {
        return std::move(*value_);
    }

    T&& operator*() && {
        return std::move(*value_);
    }

    template <typename U>
    T ValueOr(U&& default_value) const& {
        if (IsOK()) {
            return *value_;
        }

        return std::forward<U>(default_value);
    }

    template <typename U>
    T ValueOr(U&& default_value) && {
        if (IsOK()) {
            return std::move(*value_);
        }

        return std::forward<U>(default_value);
    }

private:
    std::optional<T> value_{std::nullopt};
};

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_INTERNAL_RESULT_OR_H
