#pragma once

#include <optional>
#include <string>
#include <vector>

#include "gtest/gtest.h"

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

    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_int_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<int>::min()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_unsigned_int_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<unsigned int>::max()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_int32_t_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<int32_t>::min()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_uint32_t_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<uint32_t>::max()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_long_long_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<long long>::min()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(optional_unsigned_long_long_,
            SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<unsigned long long>::max()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_int64_t_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<int64_t>::min()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_uint64_t_, SchemaOptionsBuilder.WithDefaultValue(std::numeric_limits<uint64_t>::max()))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(optional_bool_, SchemaOptionsBuilder.WithDefaultValue(true))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(optional_float_, SchemaOptionsBuilder.WithDefaultValue(1.5))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(
            optional_double_, SchemaOptionsBuilder.WithDefaultValue(100000000000000.5))
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(optional_string_, SchemaOptionsBuilder.WithDefaultValue("string"))

    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_int_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_unsigned_int_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_int32_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_uint32_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_long_long_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_unsigned_long_long_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_int64_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_uint64_t_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_bool_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_float_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_double_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(vector_string_)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_END
};

class TestCase_A_0 {
public:
    std::string JsonString() const {
        std::string json_string = R"(
{
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
        )";

        return json_string;
    }

    template <typename T>
    void Expected(T&& a) const {
        EXPECT_EQ(a.int_, std::numeric_limits<int>::min());
        EXPECT_EQ(a.unsigned_int_, std::numeric_limits<unsigned int>::max());
        EXPECT_EQ(a.int32_t_, std::numeric_limits<int32_t>::min());
        EXPECT_EQ(a.uint32_t_, std::numeric_limits<uint32_t>::max());
        EXPECT_EQ(a.long_long_, std::numeric_limits<long long>::min());
        EXPECT_EQ(a.unsigned_long_long_, std::numeric_limits<unsigned long long>::max());
        EXPECT_EQ(a.int64_t_, std::numeric_limits<int64_t>::min());
        EXPECT_EQ(a.uint64_t_, std::numeric_limits<uint64_t>::max());
        EXPECT_EQ(a.float_, 1.5);
        EXPECT_EQ(a.double_, 100000000000000.5);
        EXPECT_EQ(a.bool_, true);
        EXPECT_EQ(a.string_, "string");

        EXPECT_EQ(*a.optional_int_, std::numeric_limits<int>::min());
        EXPECT_EQ(*a.optional_unsigned_int_, std::numeric_limits<unsigned int>::max());
        EXPECT_EQ(*a.optional_int32_t_, std::numeric_limits<int32_t>::min());
        EXPECT_EQ(*a.optional_uint32_t_, std::numeric_limits<uint32_t>::max());
        EXPECT_EQ(*a.optional_long_long_, std::numeric_limits<long long>::min());
        EXPECT_EQ(*a.optional_unsigned_long_long_, std::numeric_limits<unsigned long long>::max());
        EXPECT_EQ(*a.optional_int64_t_, std::numeric_limits<int64_t>::min());
        EXPECT_EQ(*a.optional_uint64_t_, std::numeric_limits<uint64_t>::max());
        EXPECT_EQ(*a.optional_float_, 1.5);
        EXPECT_EQ(*a.optional_double_, 100000000000000.5);
        EXPECT_EQ(*a.optional_bool_, true);
        EXPECT_EQ(*a.optional_string_, "string");

        EXPECT_EQ(a.vector_int_, std::vector<int>({std::numeric_limits<int>::min(), std::numeric_limits<int>::min()}));
        EXPECT_EQ(a.vector_unsigned_int_, std::vector<unsigned int>({std::numeric_limits<unsigned int>::max(),
                                                  std::numeric_limits<unsigned int>::max()}));
        EXPECT_EQ(a.vector_int32_t_,
                std::vector<int32_t>({std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()}));
        EXPECT_EQ(a.vector_uint32_t_,
                std::vector<uint32_t>({std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max()}));
        EXPECT_EQ(a.vector_long_long_,
                std::vector<long long>({std::numeric_limits<long long>::min(), std::numeric_limits<long long>::min()}));
        EXPECT_EQ(a.vector_unsigned_long_long_,
                std::vector<unsigned long long>({std::numeric_limits<unsigned long long>::max(),
                        std::numeric_limits<unsigned long long>::max()}));
        EXPECT_EQ(a.vector_int64_t_,
                std::vector<int64_t>({std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::min()}));
        EXPECT_EQ(a.vector_uint64_t_,
                std::vector<uint64_t>({std::numeric_limits<uint64_t>::max(), std::numeric_limits<uint64_t>::max()}));
        EXPECT_EQ(a.vector_bool_, std::vector<bool>({true, true}));
        EXPECT_EQ(a.vector_float_, std::vector<float>({1.5, 1.5}));
        EXPECT_EQ(a.vector_double_, std::vector<double>({100000000000000.5, 100000000000000.5}));
        EXPECT_EQ(a.vector_string_, std::vector<std::string>({"string", "string"}));
    }

    A Instance() const {
        static A a;

        a.int_ = std::numeric_limits<int>::min();
        a.unsigned_int_ = std::numeric_limits<unsigned int>::max();
        a.int32_t_ = std::numeric_limits<int32_t>::min();
        a.uint32_t_ = std::numeric_limits<uint32_t>::max();
        a.long_long_ = std::numeric_limits<long long>::min();
        a.unsigned_long_long_ = std::numeric_limits<unsigned long long>::max();
        a.int64_t_ = std::numeric_limits<int64_t>::min();
        a.uint64_t_ = std::numeric_limits<uint64_t>::max();
        a.float_ = 1.5;
        a.double_ = 100000000000000.5;
        a.bool_ = true;
        a.string_ = "string";

        a.vector_int_ = std::vector<int>({std::numeric_limits<int>::min(), std::numeric_limits<int>::min()});
        a.vector_unsigned_int_ = std::vector<unsigned int>(
                {std::numeric_limits<unsigned int>::max(), std::numeric_limits<unsigned int>::max()});
        a.vector_int32_t_ =
                std::vector<int32_t>({std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()});
        a.vector_uint32_t_ =
                std::vector<uint32_t>({std::numeric_limits<uint32_t>::max(), std::numeric_limits<uint32_t>::max()});
        a.vector_long_long_ =
                std::vector<long long>({std::numeric_limits<long long>::min(), std::numeric_limits<long long>::min()});
        a.vector_unsigned_long_long_ = std::vector<unsigned long long>(
                {std::numeric_limits<unsigned long long>::max(), std::numeric_limits<unsigned long long>::max()});
        a.vector_int64_t_ =
                std::vector<int64_t>({std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::min()});
        a.vector_uint64_t_ =
                std::vector<uint64_t>({std::numeric_limits<uint64_t>::max(), std::numeric_limits<uint64_t>::max()});
        a.vector_bool_ = std::vector<bool>({true, true});
        a.vector_float_ = std::vector<float>({1.5, 1.5});
        a.vector_double_ = std::vector<double>({100000000000000.5, 100000000000000.5});
        a.vector_string_ = std::vector<std::string>({"string", "string"});

        return a;
    }

    std::string ToJsonStringRes() const {
        return std::string(
                R"({"int_":-2147483648,"unsigned_int_":4294967295,"int32_t_":-2147483648,"uint32_t_":4294967295,"long_long_":-9223372036854775808,"unsigned_long_long_":18446744073709551615,"int64_t_":-9223372036854775808,"uint64_t_":18446744073709551615,"bool_":true,"float_":1.5,"double_":100000000000000.5,"string_":"string","optional_int_":-2147483648,"optional_unsigned_int_":4294967295,"optional_int32_t_":-2147483648,"optional_uint32_t_":4294967295,"optional_long_long_":-9223372036854775808,"optional_unsigned_long_long_":18446744073709551615,"optional_int64_t_":-9223372036854775808,"optional_uint64_t_":18446744073709551615,"optional_bool_":true,"optional_float_":1.5,"optional_double_":100000000000000.5,"optional_string_":"string","vector_int_":[-2147483648,-2147483648],"vector_unsigned_int_":[4294967295,4294967295],"vector_int32_t_":[-2147483648,-2147483648],"vector_uint32_t_":[4294967295,4294967295],"vector_long_long_":[-9223372036854775808,-9223372036854775808],"vector_unsigned_long_long_":[18446744073709551615,18446744073709551615],"vector_int64_t_":[-9223372036854775808,-9223372036854775808],"vector_uint64_t_":[18446744073709551615,18446744073709551615],"vector_bool_":[true,true],"vector_float_":[1.5,1.5],"vector_double_":[100000000000000.5,100000000000000.5],"vector_string_":["string","string"]})");
    }

    std::string ToPrettyJsonStringRes() const {
        return std::string(R"({
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
    ]
})");
    }
};

class TestCase_A_1 {
public:
    std::string JsonString() const {
        std::string json_string = R"(
[
    {
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
    },
    {
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
]
        )";

        return json_string;
    }

    template <typename T>
    void Expected(const std::vector<T>& a_list) const {
        for (auto&& a : a_list) {
            EXPECT_EQ(a.int_, std::numeric_limits<int>::min());
            EXPECT_EQ(a.unsigned_int_, std::numeric_limits<unsigned int>::max());
            EXPECT_EQ(a.int32_t_, std::numeric_limits<int32_t>::min());
            EXPECT_EQ(a.uint32_t_, std::numeric_limits<uint32_t>::max());
            EXPECT_EQ(a.long_long_, std::numeric_limits<long long>::min());
            EXPECT_EQ(a.unsigned_long_long_, std::numeric_limits<unsigned long long>::max());
            EXPECT_EQ(a.int64_t_, std::numeric_limits<int64_t>::min());
            EXPECT_EQ(a.uint64_t_, std::numeric_limits<uint64_t>::max());
            EXPECT_EQ(a.float_, 1.5);
            EXPECT_EQ(a.double_, 100000000000000.5);
            EXPECT_EQ(a.bool_, true);
            EXPECT_EQ(a.string_, "string");

            EXPECT_EQ(*a.optional_int_, std::numeric_limits<int>::min());
            EXPECT_EQ(*a.optional_unsigned_int_, std::numeric_limits<unsigned int>::max());
            EXPECT_EQ(*a.optional_int32_t_, std::numeric_limits<int32_t>::min());
            EXPECT_EQ(*a.optional_uint32_t_, std::numeric_limits<uint32_t>::max());
            EXPECT_EQ(*a.optional_long_long_, std::numeric_limits<long long>::min());
            EXPECT_EQ(*a.optional_unsigned_long_long_, std::numeric_limits<unsigned long long>::max());
            EXPECT_EQ(*a.optional_int64_t_, std::numeric_limits<int64_t>::min());
            EXPECT_EQ(*a.optional_uint64_t_, std::numeric_limits<uint64_t>::max());
            EXPECT_EQ(*a.optional_float_, 1.5);
            EXPECT_EQ(*a.optional_double_, 100000000000000.5);
            EXPECT_EQ(*a.optional_bool_, true);
            EXPECT_EQ(*a.optional_string_, "string");

            EXPECT_EQ(a.vector_int_,
                    std::vector<int>({std::numeric_limits<int>::min(), std::numeric_limits<int>::min()}));
            EXPECT_EQ(a.vector_unsigned_int_, std::vector<unsigned int>({std::numeric_limits<unsigned int>::max(),
                                                      std::numeric_limits<unsigned int>::max()}));
            EXPECT_EQ(a.vector_int32_t_,
                    std::vector<int32_t>({std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()}));
            EXPECT_EQ(a.vector_uint32_t_, std::vector<uint32_t>({std::numeric_limits<uint32_t>::max(),
                                                  std::numeric_limits<uint32_t>::max()}));
            EXPECT_EQ(a.vector_long_long_, std::vector<long long>({std::numeric_limits<long long>::min(),
                                                   std::numeric_limits<long long>::min()}));
            EXPECT_EQ(a.vector_unsigned_long_long_,
                    std::vector<unsigned long long>({std::numeric_limits<unsigned long long>::max(),
                            std::numeric_limits<unsigned long long>::max()}));
            EXPECT_EQ(a.vector_int64_t_,
                    std::vector<int64_t>({std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::min()}));
            EXPECT_EQ(a.vector_uint64_t_, std::vector<uint64_t>({std::numeric_limits<uint64_t>::max(),
                                                  std::numeric_limits<uint64_t>::max()}));
            EXPECT_EQ(a.vector_bool_, std::vector<bool>({true, true}));
            EXPECT_EQ(a.vector_float_, std::vector<float>({1.5, 1.5}));
            EXPECT_EQ(a.vector_double_, std::vector<double>({100000000000000.5, 100000000000000.5}));
            EXPECT_EQ(a.vector_string_, std::vector<std::string>({"string", "string"}));
        }
    }
};

}  // namespace rapidjson::utils
