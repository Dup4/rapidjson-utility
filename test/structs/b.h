#pragma once

#include <string>

#include "./a.h"

#include "rapidjson_utils/rapidjson_utils.h"

namespace rapidjson::utils {

struct B {
    A a;

    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_BEGIN(B)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(a)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_END
};

class TestCase_B_0 : public TestCase_A_0 {
public:
    std::string JsonString() const {
        std::string json_string = R"(
{
    "a": {
        "int_": -2147483648,
        "unsigned_int_": 4294967295,
        "int32_t_": -2147483648,
        "uint32_t_": 4294967295,
        "long_long_": -9223372036854775808,
        "unsigned_long_long_": 18446744073709551615,
        "int64_t_": -9223372036854775808,
        "uint64_t_": 18446744073709551615,
        "bool_": true,
        "float_": 1.5,
        "double_": 100000000000000.5,
        "string_": "string",
        "vector_int_": [
            -2147483648,
            -2147483648
        ],
        "vector_unsigned_int_": [
            4294967295,
            4294967295
        ],
        "vector_int32_t_": [
            -2147483648,
            -2147483648
        ],
        "vector_uint32_t_": [
            4294967295,
            4294967295
        ],
        "vector_long_long_": [
            -9223372036854775808,
            -9223372036854775808
        ],
        "vector_unsigned_long_long_": [
            18446744073709551615,
            18446744073709551615
        ],
        "vector_int64_t_": [
            -9223372036854775808,
            -9223372036854775808
        ],
        "vector_uint64_t_": [
            18446744073709551615,
            18446744073709551615
        ],
        "vector_bool_": [
            true,
            true
        ],
        "vector_float_": [
            1.5,
            1.5
        ],
        "vector_double_": [
            100000000000000.5,
            100000000000000.5
        ],
        "vector_string_": [
            "string",
            "string"
        ]
    }
}
        )";

        return json_string;
    }

    template <typename T>
    void Expected(T&& a) const {
        TestCase_A_0::Expected(a);
    }

    template <typename T>
    void SetInstance(T&& b) const {
        TestCase_A_0::SetInstance(b.a);
    }

    B Instance() const {
        B b;
        SetInstance((b));

        return b;
    }

    std::string ToJsonStringRes() const {
        return std::string(
                R"({"a":{"int_":-2147483648,"unsigned_int_":4294967295,"int32_t_":-2147483648,"uint32_t_":4294967295,"long_long_":-9223372036854775808,"unsigned_long_long_":18446744073709551615,"int64_t_":-9223372036854775808,"uint64_t_":18446744073709551615,"bool_":true,"float_":1.5,"double_":100000000000000.5,"string_":"string","optional_int_":-2147483648,"optional_unsigned_int_":4294967295,"optional_int32_t_":-2147483648,"optional_uint32_t_":4294967295,"optional_long_long_":-9223372036854775808,"optional_unsigned_long_long_":18446744073709551615,"optional_int64_t_":-9223372036854775808,"optional_uint64_t_":18446744073709551615,"optional_bool_":true,"optional_float_":1.5,"optional_double_":100000000000000.5,"optional_string_":"string","vector_int_":[-2147483648,-2147483648],"vector_unsigned_int_":[4294967295,4294967295],"vector_int32_t_":[-2147483648,-2147483648],"vector_uint32_t_":[4294967295,4294967295],"vector_long_long_":[-9223372036854775808,-9223372036854775808],"vector_unsigned_long_long_":[18446744073709551615,18446744073709551615],"vector_int64_t_":[-9223372036854775808,-9223372036854775808],"vector_uint64_t_":[18446744073709551615,18446744073709551615],"vector_bool_":[true,true],"vector_float_":[1.5,1.5],"vector_double_":[100000000000000.5,100000000000000.5],"vector_string_":["string","string"],"optional_vector_int_":[-2147483648,-2147483648],"optional_vector_unsigned_int_":[4294967295,4294967295],"optional_vector_int32_t_":[-2147483648,-2147483648],"optional_vector_uint32_t_":[4294967295,4294967295],"optional_vector_long_long_":[-9223372036854775808,-9223372036854775808],"optional_vector_unsigned_long_long_":[18446744073709551615,18446744073709551615],"optional_vector_int64_t_":[-9223372036854775808,-9223372036854775808],"optional_vector_uint64_t_":[18446744073709551615,18446744073709551615],"optional_vector_bool_":[true,true],"optional_vector_float_":[1.5,1.5],"optional_vector_double_":[100000000000000.5,100000000000000.5],"optional_vector_string_":["string","string"]}})");
    };

    std::string ToPrettyJsonStringRes() const {
        return std::string(R"({
    "a": {
        "int_": -2147483648,
        "unsigned_int_": 4294967295,
        "int32_t_": -2147483648,
        "uint32_t_": 4294967295,
        "long_long_": -9223372036854775808,
        "unsigned_long_long_": 18446744073709551615,
        "int64_t_": -9223372036854775808,
        "uint64_t_": 18446744073709551615,
        "bool_": true,
        "float_": 1.5,
        "double_": 100000000000000.5,
        "string_": "string",
        "optional_int_": -2147483648,
        "optional_unsigned_int_": 4294967295,
        "optional_int32_t_": -2147483648,
        "optional_uint32_t_": 4294967295,
        "optional_long_long_": -9223372036854775808,
        "optional_unsigned_long_long_": 18446744073709551615,
        "optional_int64_t_": -9223372036854775808,
        "optional_uint64_t_": 18446744073709551615,
        "optional_bool_": true,
        "optional_float_": 1.5,
        "optional_double_": 100000000000000.5,
        "optional_string_": "string",
        "vector_int_": [
            -2147483648,
            -2147483648
        ],
        "vector_unsigned_int_": [
            4294967295,
            4294967295
        ],
        "vector_int32_t_": [
            -2147483648,
            -2147483648
        ],
        "vector_uint32_t_": [
            4294967295,
            4294967295
        ],
        "vector_long_long_": [
            -9223372036854775808,
            -9223372036854775808
        ],
        "vector_unsigned_long_long_": [
            18446744073709551615,
            18446744073709551615
        ],
        "vector_int64_t_": [
            -9223372036854775808,
            -9223372036854775808
        ],
        "vector_uint64_t_": [
            18446744073709551615,
            18446744073709551615
        ],
        "vector_bool_": [
            true,
            true
        ],
        "vector_float_": [
            1.5,
            1.5
        ],
        "vector_double_": [
            100000000000000.5,
            100000000000000.5
        ],
        "vector_string_": [
            "string",
            "string"
        ],
        "optional_vector_int_": [
            -2147483648,
            -2147483648
        ],
        "optional_vector_unsigned_int_": [
            4294967295,
            4294967295
        ],
        "optional_vector_int32_t_": [
            -2147483648,
            -2147483648
        ],
        "optional_vector_uint32_t_": [
            4294967295,
            4294967295
        ],
        "optional_vector_long_long_": [
            -9223372036854775808,
            -9223372036854775808
        ],
        "optional_vector_unsigned_long_long_": [
            18446744073709551615,
            18446744073709551615
        ],
        "optional_vector_int64_t_": [
            -9223372036854775808,
            -9223372036854775808
        ],
        "optional_vector_uint64_t_": [
            18446744073709551615,
            18446744073709551615
        ],
        "optional_vector_bool_": [
            true,
            true
        ],
        "optional_vector_float_": [
            1.5,
            1.5
        ],
        "optional_vector_double_": [
            100000000000000.5,
            100000000000000.5
        ],
        "optional_vector_string_": [
            "string",
            "string"
        ]
    }
})");
    }
};

}  // namespace rapidjson::utils
