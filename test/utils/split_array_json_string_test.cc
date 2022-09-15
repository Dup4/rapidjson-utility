#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <string_view>

#include "rapidjson-utility/utility/split_array_json_string.h"

namespace rapidjson_utility {

class SplitArrayJsonStringTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(SplitArrayJsonStringTest, split_array_json_string) {
    {
        std::invoke([]() -> Result {
            constexpr std::string_view json_string = R"(
[
    {
        "a": 1,
        "b": 2
    },
    {
        "a": 3,
        "b": 4
    },
    {
        "a": 1
    }
]
        )";

            RESULT_VALUE_OR_RETURN(auto split_json_string_vec, SplitArrayJsonString(json_string));

            auto expected_split_json_string_vec = std::vector<std::string>{
                    std::string(R"({"a":1,"b":2})"),
                    std::string(R"({"a":3,"b":4})"),
                    std::string(R"({"a":1})"),
            };

            EXPECT_EQ(split_json_string_vec, expected_split_json_string_vec);

            return Result::OK();
        }).NotOKThen([]([[maybe_unused]] auto&& res) {
            EXPECT_TRUE(false);
        });
    }
}

}  // namespace rapidjson_utility
