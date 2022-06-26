#include "gtest/gtest.h"

#include "rapidjson/document.h"

class RapidJsonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(RapidJsonTest, document_test) {
    {
        const char* json_string = R"(
{
    "a": 1,
    "b": 2
}
    )";

        rapidjson::Document doc;
        doc.Parse(json_string);

        auto value = doc.GetObject();

        EXPECT_EQ(value["a"], 1);
        EXPECT_EQ(value["b"], 2);
    }

    {
        const char* json_string = R"(
[
    1,
    2,
    3
]
    )";

        rapidjson::Document doc;
        doc.Parse(json_string);

        auto value = doc.GetArray();

        EXPECT_EQ(value[0], 1);
        EXPECT_EQ(value[1], 2);
        EXPECT_EQ(value[2], 3);
    }
}
