#ifndef RAPIDJSON_UTILS_INTERNAL_RESULT_H
#define RAPIDJSON_UTILS_INTERNAL_RESULT_H

#include <string>

namespace rapidjson::utils {

namespace internal {

enum class ResultErrorCode {
    kNoError = 0,
    kParseError,
};

template <typename T>
class Result {
public:
    Result() = default;
    template <typename U>
    Result(U&& value) : value_(std::move(value)) {}
    Result(ResultErrorCode error_code, const std::string& error_message = "")
            : error_code_(error_code), error_message_(error_message) {}

    const T& Value() const& {
        return value_;
    }

    T& Value() & {
        return value_;
    }

    const T&& Value() const&& {
        return std::move(value_);
    }

    T&& Value() && {
        return std::move(value_);
    }

    const T& operator*() const& {
        return value_;
    }

    T& operator*() & {
        return value_;
    }

    const T&& operator*() const&& {
        return std::move(value_);
    }

    T&& operator*() && {
        return std::move(value_);
    }

    bool IsOK() const {
        return error_code_ == ResultErrorCode::kNoError;
    }

    template <typename U>
    T ValueOr(U&& default_value) const& {
        if (IsOK()) {
            return value_;
        }

        return std::forward<U>(default_value);
    }

    template <typename U>
    T ValueOr(U&& default_value) && {
        if (IsOK()) {
            return std::move(value_);
        }

        return std::forward<U>(default_value);
    }

    ResultErrorCode ErrorCode() const {
        return error_code_;
    }

    std::string ErrorMessage() const {
        return error_message_;
    }

private:
    ResultErrorCode error_code_{ResultErrorCode::kNoError};
    std::string error_message_{"No error."};
    T value_;
};

}  // namespace internal

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_INTERNAL_RESULT_H
