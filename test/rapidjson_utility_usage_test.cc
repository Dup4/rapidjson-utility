#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "rapidjson-utility/rapidjson-utility.h"

using namespace rapidjson_utility;

class RapidJsonUtilityUsageTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

struct Node {
    int int_;
    int64_t int64_t_;
    bool bool_;
    float float_;
    double double_;
    std::string string_;
    std::vector<int> vector_int_;

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_BEGIN(Node)

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(int_)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(int64_t_)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(bool_)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(float_)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(double_)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(string_)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(vector_int_)

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_END
};

TEST_F(RapidJsonUtilityUsageTest, from_and_to_json) {
    auto node = Node();
    node.int_ = 2;
    node.int64_t_ = int64_t(0x3f3f3f3f3f3f3f3f);
    node.bool_ = true;
    node.float_ = 0;
    node.double_ = 0;
    node.string_ = "test_string";
    node.vector_int_ = std::vector<int>(2, 4);

    std::invoke([&]() -> Result {
        RESULT_VALUE_OR_RETURN(const auto json, RapidJsonUtility.ToJson.GetPrettyJsonString(&node));
        EXPECT_EQ(json, std::string(R"({
    "int_": 2,
    "int64_t_": 4557430888798830399,
    "bool_": true,
    "float_": 0.0,
    "double_": 0.0,
    "string_": "test_string",
    "vector_int_": [
        4,
        4
    ]
})"));

        RESULT_VALUE_OR_RETURN(const auto new_node, RapidJsonUtility.FromJson.New<Node>(json));

        EXPECT_EQ(new_node.int_, 2);
        EXPECT_EQ(new_node.int64_t_, 4557430888798830399);
        EXPECT_EQ(new_node.bool_, true);
        EXPECT_EQ(new_node.float_, 0.000000);
        EXPECT_EQ(new_node.double_, 0.000000);
        EXPECT_EQ(new_node.string_, std::string("test_string"));
        EXPECT_EQ(new_node.vector_int_,
                  std::vector<int>({
                          4,
                          4,
                  }));

        return Result::OK();
    }).NotOKThen([](auto&& res) {
        EXPECT_TRUE(false) << res.PrettyMessage() << std::endl;
    });
}
