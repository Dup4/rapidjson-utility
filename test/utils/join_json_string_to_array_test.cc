#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <string_view>

#include "rapidjson_utility/utility/join_json_string_to_array.h"

namespace rapidjson_utility {

class JoinJsonStringToArrayTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(JoinJsonStringToArrayTest, join_json_string_to_array) {
    {
        std::invoke([]() -> Result {
            static const std::vector<std::string> json_string_array = std::vector<std::string>{
                    std::string(R"({"a":1,"b":2})"),
                    std::string(R"({"a":3,"b":4})"),
                    std::string(R"({"a":1})"),
            };

            RESULT_VALUE_OR_RETURN(auto json_string, JoinJsonStringToArray(json_string_array));
            EXPECT_EQ(json_string, std::string(R"([{"a":1,"b":2},{"a":3,"b":4},{"a":1}])"));

            return Result::OK();
        }).NotOKThen([]([[maybe_unused]] auto&& res) {
            EXPECT_TRUE(false);
        });
    }
}

}  // namespace rapidjson_utility
