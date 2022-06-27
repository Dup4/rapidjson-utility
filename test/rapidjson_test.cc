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

    {
        rapidjson::Document doc;
        doc.SetObject();

        auto get_value = [&doc]() {
            rapidjson::Value value;
            value.SetObject();
            value.AddMember("test", "dd", doc.GetAllocator());
            return value;
        };

        doc.AddMember("test", get_value(), doc.GetAllocator());
        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"({"test":{"test":"dd"}})");
    }

    {
        rapidjson::Document doc;
        doc.SetObject();

        rapidjson::Document sub_doc;
        sub_doc.SetObject();

        rapidjson::Value key_name_value;
        key_name_value.SetString("test", sub_doc.GetAllocator());

        sub_doc.AddMember(key_name_value, "dd", sub_doc.GetAllocator());

        doc.AddMember("test", sub_doc, doc.GetAllocator());

        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"({"test":{"test":"dd"}})");
    }

    {
        rapidjson::Document doc;
        doc.SetArray();
        rapidjson::Document sub_doc;
        sub_doc.SetString("dd");
        doc.PushBack(sub_doc, doc.GetAllocator());
        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"(["dd"])");
    }

    {
        rapidjson::Document doc;
        doc.SetObject();

        auto sub_doc = std::invoke([]() -> rapidjson::utils::ResultOr<rapidjson::Document> {
            rapidjson::Document sub_doc;
            sub_doc.SetArray();

            sub_doc.PushBack(rapidjson::Value(1).Move(), sub_doc.GetAllocator());
            sub_doc.PushBack(rapidjson::Value(2).Move(), sub_doc.GetAllocator());

            return sub_doc;
        });

        auto sub_doc_1 = std::invoke([]() -> rapidjson::utils::ResultOr<rapidjson::Document> {
            rapidjson::Document sub_doc_1;
            sub_doc_1.SetArray();

            sub_doc_1.PushBack(rapidjson::Value(3).Move(), sub_doc_1.GetAllocator());
            sub_doc_1.PushBack(rapidjson::Value(4).Move(), sub_doc_1.GetAllocator());

            return sub_doc_1;
        });

        doc.AddMember(rapidjson::Value("test", doc.GetAllocator()).Move(), sub_doc.Value(), doc.GetAllocator());
        doc.AddMember(rapidjson::Value("test_1", doc.GetAllocator()).Move(), sub_doc_1.Value(), doc.GetAllocator());
        auto json_string = rapidjson::utils::GetJsonString(doc);
        EXPECT_EQ(json_string, R"({"test":[1,2],"test_1":[3,4]})");
    }
}
