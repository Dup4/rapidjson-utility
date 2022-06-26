#pragma once

#include <optional>
#include <string>

#include "rapidjson_utils/rapidjson_utils.h"

namespace rapidjson::utils {

struct A {
    int int_;
    unsigned int unsigned_int_;
    int32_t int32_t_;
    uint32_t uint32_t_;
    long long long_long_;
    unsigned long long unsigned_long_long_;
    int64_t int64_t_;
    uint64_t uint64_t_;
    bool bool_;
    float float_;
    double double_;
    std::string string_;

    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_BEGIN(A)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(int_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(unsigned_int_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(int32_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(uint32_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(long_long_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(unsigned_long_long_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(int64_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(uint64_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(bool_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(float_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(double_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(string_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_END
};

}  // namespace rapidjson::utils
