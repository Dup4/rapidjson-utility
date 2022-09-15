#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <vector>

#include "rapidjson-utility/internal/schema_options.h"

namespace rapidjson_utility {

class SchemaOptionsTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(SchemaOptionsTest, schema_options_test) {
    {
        internal::SchemaOptionsStruct<int> o;

        SchemaOptions::ApplySchemaOptions(o, SchemaOptions::WithKeyName("key"), SchemaOptions::WithDefaultValue(1));

        EXPECT_EQ(o.key_name, "key");
        EXPECT_TRUE(o.default_value.has_value());
        EXPECT_EQ(*o.default_value, 1);
    }

    {
        internal::SchemaOptionsStruct<std::vector<int>> o;
        SchemaOptions::ApplySchemaOptions(o, SchemaOptions::WithDefaultValue(std::vector<int>({1, 2, 3})));
        EXPECT_TRUE(o.default_value.has_value());
        auto expected = std::vector<int>({1, 2, 3});
        EXPECT_EQ(*o.default_value, expected);
    }
}

}  // namespace rapidjson_utility
