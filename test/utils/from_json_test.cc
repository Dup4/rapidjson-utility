#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <limits>

#include "rapidjson_utils/rapidjson_utils.h"
#include "rapidjson_utils/utils/from_json.h"

#include "../structs/a.h"
#include "../structs/b.h"
#include "../structs/c.h"
#include "../structs/d.h"

namespace rapidjson::utils {

class FromJsonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(FromJsonTest, from_json_a_and_c_test) {
    {
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

        {
            A a;
            auto res = FromJson(json_string, &a);
            EXPECT_TRUE(res.IsOK());
        }

        {
            C c;
            auto res = FromJson(json_string, &c);
            EXPECT_TRUE(res.IsOK());
        }

        {
            auto expected = [](auto&& a) {
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
                EXPECT_EQ(a.vector_int32_t_, std::vector<int32_t>({std::numeric_limits<int32_t>::min(),
                                                     std::numeric_limits<int32_t>::min()}));
                EXPECT_EQ(a.vector_uint32_t_, std::vector<uint32_t>({std::numeric_limits<uint32_t>::max(),
                                                      std::numeric_limits<uint32_t>::max()}));
                EXPECT_EQ(a.vector_long_long_, std::vector<long long>({std::numeric_limits<long long>::min(),
                                                       std::numeric_limits<long long>::min()}));
                EXPECT_EQ(a.vector_unsigned_long_long_,
                        std::vector<unsigned long long>({std::numeric_limits<unsigned long long>::max(),
                                std::numeric_limits<unsigned long long>::max()}));
                EXPECT_EQ(a.vector_int64_t_, std::vector<int64_t>({std::numeric_limits<int64_t>::min(),
                                                     std::numeric_limits<int64_t>::min()}));
                EXPECT_EQ(a.vector_uint64_t_, std::vector<uint64_t>({std::numeric_limits<uint64_t>::max(),
                                                      std::numeric_limits<uint64_t>::max()}));
                EXPECT_EQ(a.vector_bool_, std::vector<bool>({true, true}));
                EXPECT_EQ(a.vector_float_, std::vector<float>({1.5, 1.5}));
                EXPECT_EQ(a.vector_double_, std::vector<double>({100000000000000.5, 100000000000000.5}));
                EXPECT_EQ(a.vector_string_, std::vector<std::string>({"string", "string"}));
            };

            {
                auto res = FromJson.New<A>(json_string);
                EXPECT_TRUE(res.IsOK());
                A a = std::move(res.Value());
                expected(a);
            }

            {
                auto res = FromJson.New<C>(json_string);
                EXPECT_TRUE(res.IsOK());
                C c = std::move(res.Value());
                expected(c);
            }
        }
    }
}

TEST_F(FromJsonTest, from_json_b_and_d_test) {
    {
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

        auto expected = [](auto&& a) {
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
        };

        {
            B b;
            auto res = FromJson(json_string, &b);
            EXPECT_TRUE(res.IsOK());
            expected(b.a);
        }

        {
            D d;
            auto res = FromJson(json_string, &d);
            EXPECT_TRUE(res.IsOK());
            expected(d.c);
        }
    }
}

TEST_F(FromJsonTest, from_json_vector_test) {
    {
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

        auto expected = [](auto&& a) {
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
        };

        {
            std::vector<A> a_list;
            auto res = FromJson(json_string, &a_list);
            EXPECT_TRUE(res.IsOK());
            EXPECT_EQ(a_list.size(), 2);
            expected(a_list[0]);
            expected(a_list[1]);
        }
    }
}

}  // namespace rapidjson::utils
