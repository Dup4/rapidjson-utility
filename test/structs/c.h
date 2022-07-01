#pragma once

#include <optional>
#include <string>
#include <vector>

#include "rapidjson_utility/rapidjson_utility.h"

#include "./a.h"

namespace rapidjson_utility {

struct C {
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

    std::optional<int> optional_int_;
    std::optional<unsigned int> optional_unsigned_int_;
    std::optional<int32_t> optional_int32_t_;
    std::optional<uint32_t> optional_uint32_t_;
    std::optional<long long> optional_long_long_;
    std::optional<unsigned long long> optional_unsigned_long_long_;
    std::optional<int64_t> optional_int64_t_;
    std::optional<uint64_t> optional_uint64_t_;
    std::optional<bool> optional_bool_;
    std::optional<float> optional_float_;
    std::optional<double> optional_double_;
    std::optional<std::string> optional_string_;

    std::vector<int> vector_int_;
    std::vector<unsigned int> vector_unsigned_int_;
    std::vector<int32_t> vector_int32_t_;
    std::vector<uint32_t> vector_uint32_t_;
    std::vector<long long> vector_long_long_;
    std::vector<unsigned long long> vector_unsigned_long_long_;
    std::vector<int64_t> vector_int64_t_;
    std::vector<uint64_t> vector_uint64_t_;
    std::vector<bool> vector_bool_;
    std::vector<float> vector_float_;
    std::vector<double> vector_double_;
    std::vector<std::string> vector_string_;

    std::optional<std::vector<int>> optional_vector_int_;
    std::optional<std::vector<unsigned int>> optional_vector_unsigned_int_;
    std::optional<std::vector<int32_t>> optional_vector_int32_t_;
    std::optional<std::vector<uint32_t>> optional_vector_uint32_t_;
    std::optional<std::vector<long long>> optional_vector_long_long_;
    std::optional<std::vector<unsigned long long>> optional_vector_unsigned_long_long_;
    std::optional<std::vector<int64_t>> optional_vector_int64_t_;
    std::optional<std::vector<uint64_t>> optional_vector_uint64_t_;
    std::optional<std::vector<bool>> optional_vector_bool_;
    std::optional<std::vector<float>> optional_vector_float_;
    std::optional<std::vector<double>> optional_vector_double_;
    std::optional<std::vector<std::string>> optional_vector_string_;
};

RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_BEGIN(C)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(int_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(unsigned_int_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(int32_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(uint32_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(long_long_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(unsigned_long_long_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(int64_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(uint64_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(bool_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(float_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(double_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(string_)

RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_int_, SchemaOptions::WithDefaultValue(std::numeric_limits<int>::min()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_unsigned_int_, SchemaOptions::WithDefaultValue(std::numeric_limits<unsigned int>::max()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_int32_t_, SchemaOptions::WithDefaultValue(std::numeric_limits<int32_t>::min()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_uint32_t_, SchemaOptions::WithDefaultValue(std::numeric_limits<uint32_t>::max()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_long_long_, SchemaOptions::WithDefaultValue(std::numeric_limits<long long>::min()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_unsigned_long_long_, SchemaOptions::WithDefaultValue(std::numeric_limits<unsigned long long>::max()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_int64_t_, SchemaOptions::WithDefaultValue(std::numeric_limits<int64_t>::min()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_uint64_t_, SchemaOptions::WithDefaultValue(std::numeric_limits<uint64_t>::max()))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_bool_, SchemaOptions::WithDefaultValue(true))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_float_, SchemaOptions::WithDefaultValue(1.5))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_double_, SchemaOptions::WithDefaultValue(100000000000000.5))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_string_, SchemaOptions::WithDefaultValue("string"))

RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_int_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_unsigned_int_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_int32_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_uint32_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_long_long_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_unsigned_long_long_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_int64_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_uint64_t_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_bool_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_float_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_double_)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(vector_string_)

RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_int_,
        SchemaOptions::WithDefaultValue(
                std::vector<int>{std::numeric_limits<int>::min(), std::numeric_limits<int>::min()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_unsigned_int_,
        SchemaOptions::WithDefaultValue(std::vector<unsigned int>{
                std::numeric_limits<unsigned int>::max(), std::numeric_limits<unsigned int>::max()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_int32_t_,
        SchemaOptions::WithDefaultValue(
                std::vector<int32_t>{std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_uint32_t_,
        SchemaOptions::WithDefaultValue(
                std::vector<uint32_t>{std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_long_long_,
        SchemaOptions::WithDefaultValue(
                std::vector<long long>{std::numeric_limits<long long>::min(), std::numeric_limits<long long>::min()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_unsigned_long_long_,
        SchemaOptions::WithDefaultValue(std::vector<unsigned long long>{
                std::numeric_limits<unsigned long long>::max(), std::numeric_limits<unsigned long long>::max()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_int64_t_,
        SchemaOptions::WithDefaultValue(
                std::vector<int64_t>{std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::min()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_uint64_t_,
        SchemaOptions::WithDefaultValue(
                std::vector<uint64_t>{std::numeric_limits<uint64_t>::max(), std::numeric_limits<uint64_t>::max()}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_vector_bool_, SchemaOptions::WithDefaultValue(std::vector<bool>{true, true}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_vector_float_, SchemaOptions::WithDefaultValue(std::vector<float>{1.5, 1.5}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(optional_vector_double_,
        SchemaOptions::WithDefaultValue(std::vector<double>{100000000000000.5, 100000000000000.5}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(
        optional_vector_string_, SchemaOptions::WithDefaultValue(std::vector<std::string>{"string", "string"}))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_END

}  // namespace rapidjson_utility
