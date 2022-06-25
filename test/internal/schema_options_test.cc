#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <vector>

#include "rapidjson_utils/internal/schema_options.h"

namespace rapidjson::utils {

class SchemaOptionsTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(SchemaOptionsTest, schema_options_test) {
    {
        SchemaOptions<int> o;

        SchemaOptionsBuilder.ApplySchemaOptions(
                o, SchemaOptionsBuilder.WithKey("key"), SchemaOptionsBuilder.WithDefaultValue(1));

        EXPECT_EQ(o.key, "key");
        EXPECT_TRUE(o.default_value.has_value());
        EXPECT_EQ(*o.default_value, 1);
    }

    {
        SchemaOptions<std::vector<int>> o;
        SchemaOptionsBuilder.ApplySchemaOptions(o, SchemaOptionsBuilder.WithDefaultValue(std::vector<int>({1, 2, 3})));
        EXPECT_TRUE(o.default_value.has_value());
        auto expected = std::vector<int>({1, 2, 3});
        EXPECT_EQ(*o.default_value, expected);
    }
}

}  // namespace rapidjson::utils
