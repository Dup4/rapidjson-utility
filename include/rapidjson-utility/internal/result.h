#ifndef RAPIDJSON_UTILITY_INTERNAL_RESULT_H
#define RAPIDJSON_UTILITY_INTERNAL_RESULT_H

#include <map>
#include <string>

#include "result/result.h"     // IWYU pragma: export
#include "result/result_or.h"  // IWYU pragma: export

namespace rapidjson_utility {

enum class ErrorCode {
    OK = 0,
    NestedError,
    ParseError,
    MemberNotFoundError,
    ValidateError,
    OtherError,
};

inline auto ErrorCodeToStr(ErrorCode error_code) {
    static const std::map<ErrorCode, std::string> ErrorCodeToStrMap = {
            {ErrorCode::OK, "OK"},
            {ErrorCode::NestedError, "NestedError"},
            {ErrorCode::ParseError, "ParseError"},
            {ErrorCode::MemberNotFoundError, "MemberNotFoundError"},
            {ErrorCode::ValidateError, "ValidateError"},
            {ErrorCode::OtherError, "OtherError"},
    };

    if (ErrorCodeToStrMap.count(error_code) == 0) {
        return ErrorCodeToStrMap.rbegin()->second;
    }

    return ErrorCodeToStrMap.at(error_code);
}

using Result = result::Result<ErrorCode>;

template <typename T>
using ResultOr = result::ResultOr<Result, T>;

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_INTERNAL_RESULT_H
