#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "rapidjson/document.h"

#include "rapidjson_utils/rapidjson_utils.h"

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

    {
        rapidjson::Document doc;
        doc.SetObject();
        doc.AddMember("test", "dd", doc.GetAllocator());
        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"({"test":"dd"})");
    }

    {
        rapidjson::Document doc;
        doc.SetObject();
        rapidjson::Value value;
        value.SetObject();
        value.AddMember("test", "dd", doc.GetAllocator());
        doc.AddMember("test", value, doc.GetAllocator());
        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"({"test":{"test":"dd"}})");
    }

    {
        rapidjson::Document doc;
        doc.SetArray();
        doc.PushBack("1", doc.GetAllocator());
        doc.PushBack("2", doc.GetAllocator());
        doc.PushBack("3", doc.GetAllocator());
        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"(["1","2","3"])");
    }
}
