#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include "rapidjson_utils/utils/get_pretty_format_json_string.h"
#include "rapidjson_utils/utils/get_pretty_parse_result_message.h"

class GetPrettyFormatJsonString : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(GetPrettyFormatJsonString, get_pretty_format_json_string_test) {
    {
        auto res = rapidjson::utils::GetPrettyFormatJsonString("{]");
        EXPECT_FALSE(res.IsOK());
        EXPECT_EQ(res.ErrorMessage(), std::string("Missing a name for object member. at offset 1"));
    }

    {
        const char* json_string = R"(
{
    "a": 1,
    "b": 2,
    "c": 3,
    "d": 4,
    "e": 5,
    "f": 6,
    "g": 7,
    "h": 8,
    "i": 9,
    "j": 10,
    "k": 11,
    "l": 12,
    "m": 13,
    "n": 14,
    "o": 15,
    "p": 16,
    "q": 17,
    "r": 18,
    "s": 19,
    "t": 20,
    "u": 21,
    "v": 22,
    "w": 23,
    "x": 24,
    "y": 25,
    "z": 26
}
    )";

        auto res = rapidjson::utils::GetPrettyFormatJsonString(json_string);
        EXPECT_TRUE(res.IsOK());
        EXPECT_EQ(res.ErrorMessage(), std::string("No error."));

        auto expected_pretty_json_string = std::string(R"({
    "a": 1,
    "b": 2,
    "c": 3,
    "d": 4,
    "e": 5,
    "f": 6,
    "g": 7,
    "h": 8,
    "i": 9,
    "j": 10,
    "k": 11,
    "l": 12,
    "m": 13,
    "n": 14,
    "o": 15,
    "p": 16,
    "q": 17,
    "r": 18,
    "s": 19,
    "t": 20,
    "u": 21,
    "v": 22,
    "w": 23,
    "x": 24,
    "y": 25,
    "z": 26
})");

        EXPECT_EQ(res.Value(), expected_pretty_json_string);
        EXPECT_EQ(*res, expected_pretty_json_string);
    }
}
