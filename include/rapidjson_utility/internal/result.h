#ifndef RAPIDJSON_UTILITY_INTERNAL_RESULT_H
#define RAPIDJSON_UTILITY_INTERNAL_RESULT_H

#include <map>
#include <string>

namespace rapidjson_utility {

enum class ErrorCode {
    kOK = 0,
    kParseError,
    kMemberNotFoundError,
    kValidateError,
    kOtherError,
};

static std::map<ErrorCode, std::string> ErrorCodeToStr = {
        {ErrorCode::kOK, "OK"},
        {ErrorCode::kParseError, "ParseError"},
        {ErrorCode::kMemberNotFoundError, "MemberNotFoundError"},
        {ErrorCode::kValidateError, "ValidateError"},
        {ErrorCode::kOtherError, "OtherError"},
};

class Result {
public:
    Result() = default;
    Result(ErrorCode error_code, std::string_view error_message = "")
            : error_code_(error_code), error_message_(error_message) {}

    Result(const Result&) = default;
    Result& operator=(const Result&) = default;
    Result(Result&&) = default;
    Result& operator=(Result&&) = default;

    bool IsOK() const {
        return error_code_ == ErrorCode::kOK;
    }

    ErrorCode Code() const {
        return error_code_;
    }

    std::string Message() const {
        return error_message_;
    }

private:
    ErrorCode error_code_{ErrorCode::kOK};
    std::string error_message_{ErrorCodeToStr.at(ErrorCode::kOK)};
};

inline bool IsOK(const Result& result) {
    return result.Code() == ErrorCode::kOK;
}

inline bool IsParseError(const Result& result) {
    return result.Code() == ErrorCode::kParseError;
}

inline bool IsMemberNotFoundError(const Result& result) {
    return result.Code() == ErrorCode::kMemberNotFoundError;
}

inline bool IsValidateError(const Result& result) {
    return result.Code() == ErrorCode::kValidateError;
}

inline bool IsOtherError(const Result& result) {
    return result.Code() == ErrorCode::kOtherError;
}

inline Result OKResult(std::string_view error_message = ErrorCodeToStr.at(ErrorCode::kOK)) {
    return Result(ErrorCode::kOK, error_message);
}

inline Result ParseErrorResult(std::string_view error_message = ErrorCodeToStr.at(ErrorCode::kParseError)) {
    return Result(ErrorCode::kParseError, error_message);
}

inline Result MemberNotFoundErrorResult(
        std::string_view error_message = ErrorCodeToStr.at(ErrorCode::kMemberNotFoundError)) {
    return Result(ErrorCode::kMemberNotFoundError, error_message);
}

inline Result ValidateErrorResult(std::string_view error_message = ErrorCodeToStr.at(ErrorCode::kValidateError)) {
    return Result(ErrorCode::kValidateError, error_message);
}

inline Result OtherErrorResult(std::string_view error_message = ErrorCodeToStr.at(ErrorCode::kOtherError)) {
    return Result(ErrorCode::kOtherError, error_message);
}

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_INTERNAL_RESULT_H