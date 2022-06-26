#include "rapidjson_utils/utils/from_json.h"
#include <limits>
#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "rapidjson_utils/rapidjson_utils.h"

#include "../structs/a.h"

namespace rapidjson::utils {

class FromJsonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(FromJsonTest, from_json_test) {
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
    "string_": "string"
}
        )";

        A a;
        auto res = FromJson(json_string, &a);
        EXPECT_TRUE(res.IsOK());
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
    }
}

}  // namespace rapidjson::utils
