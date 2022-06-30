#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "rapidjson_utility/utility/merge_objects.h"

namespace rapidjson::utility {

class MergeObjectsTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(MergeObjectsTest, merge_objects_test) {
    {
        const auto* json_dst = R"(
{
    "a": 1,
    "b": 2,
    "c": 3
}
    )";

        const auto* json_src = R"(
{
    "a": 2,
    "b": 3,
    "d": 4
}
    )";

        auto merge_json_string = MergeObjects(json_dst, json_src);
        EXPECT_TRUE(merge_json_string.IsOK());
        EXPECT_EQ(merge_json_string.Value(), std::string(R"({"a":2,"b":3,"c":3,"d":4})"));
    }
}

}  // namespace rapidjson::utility
