#include "rapidjson_utility/utility/to_json.h"
#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <limits>

#include "rapidjson_utility/rapidjson_utility.h"

#include "../structs/a.h"
#include "../structs/b.h"
#include "../structs/c.h"
#include "../structs/d.h"
#include "../structs/e.h"
#include "../structs/f.h"
#include "../structs/g.h"

namespace rapidjson_utility {

class ToJsonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(ToJsonTest, to_json_a_and_c_test) {
    {
        auto tc = TestCase_A_0();
        auto a = tc.Instance();

        auto json_string_res = ToJson(&a);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&a);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_A_0();
        const auto a = tc.Instance();

        auto json_string_res = ToJson(&a);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&a);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_A_1();
        auto a_list = tc.Instance();

        auto json_string_res = ToJson(&a_list);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&a_list);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_A_1();
        const auto a_list = tc.Instance();

        auto json_string_res = ToJson(&a_list);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&a_list);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_B_0();
        auto b = tc.Instance();

        auto json_string_res = ToJson(&b);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&b);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_B_0();
        const auto b = tc.Instance();

        auto json_string_res = ToJson(&b);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&b);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_A_0();
        C c = [&tc]() {
            C c;
            tc.SetInstance(c);
            return c;
        }();

        auto json_string_res = ToJson(&c);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&c);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_A_0();
        const C c = [&tc]() {
            C c;
            tc.SetInstance(c);
            return c;
        }();

        auto json_string_res = ToJson(&c);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&c);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_B_0();
        D d = []() {
            D d;
            auto tc = TestCase_A_0();
            tc.SetInstance(d.c);
            return d;
        }();

        auto json_string_res = ToJson(&d);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&d);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }

    {
        auto tc = TestCase_B_0();
        const D d = []() {
            D d;
            auto tc = TestCase_A_0();
            tc.SetInstance(d.c);
            return d;
        }();

        auto json_string_res = ToJson(&d);
        EXPECT_TRUE(json_string_res.IsOK());
        auto json_string = json_string_res.Value();
        EXPECT_EQ(json_string, tc.ToJsonStringRes());

        auto pretty_json_string_res = ToJson.GetPrettyJsonString(&d);
        EXPECT_TRUE(pretty_json_string_res.IsOK());
        auto pretty_json_string = pretty_json_string_res.Value();
        EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
    }
}

TEST_F(ToJsonTest, to_json_enum_test) {
    {
        F f;
        f.e = FEnum::B;

        auto res = ToJson(&f);
        EXPECT_TRUE(res.IsOK());
        auto json_string = res.Value();
        EXPECT_EQ(json_string, R"({"e":1})");
    }
}

TEST_F(ToJsonTest, to_json_map_string_t_test) {
    {
        auto tc = TestCase_G_0();
        auto g = tc.Instance();

        {
            auto res = ToJson(&g);
            EXPECT_TRUE(res.IsOK());

            auto json_string = res.Value();
            EXPECT_EQ(json_string, tc.ToJsonStringRes());
        }

        {
            auto res = ToJson.GetPrettyJsonString(&g);
            EXPECT_TRUE(res.IsOK());

            auto pretty_json_string = res.Value();
            EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
        }
    }
}

TEST_F(ToJsonTest, to_json_map_test) {
    {
        auto tc = TestCase_A_2();

        auto map_a = tc.Instance();

        {
            auto res = ToJson(&map_a);
            EXPECT_TRUE(res.IsOK());

            auto json_string = res.Value();
            EXPECT_EQ(json_string, tc.ToJsonStringRes());
        }

        {
            auto res = ToJson.GetPrettyJsonString(&map_a);
            EXPECT_TRUE(res.IsOK());

            auto pretty_json_string = res.Value();
            EXPECT_EQ(pretty_json_string, tc.ToPrettyJsonStringRes());
        }
    }
}

}  // namespace rapidjson_utility
