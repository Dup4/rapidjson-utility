#include "gtest/gtest.h"
#include "rapidjson-utility/internal/macros.h"
#include "snapshot/snapshot.h"

#include <limits>
#include <string>

#include "rapidjson-utility/rapidjson-utility.h"

#include "../structs/a.h"
#include "../structs/b.h"
#include "../structs/c.h"
#include "../structs/d.h"
#include "../structs/e.h"
#include "../structs/f.h"
#include "../structs/g.h"

namespace rapidjson_utility {

class FromJsonTest : public testing::Test {
protected:
    virtual void SetUp() override {}
};

TEST_F(FromJsonTest, from_json_a_and_c_test) {
    {
        auto tc = TestCase_A_0();
        A a;
        auto res = FromJson(tc.JsonString(), &a);
        EXPECT_TRUE(res.IsOK());
        tc.Expected(a);
    }

    {
        auto tc = TestCase_A_0();
        C c;
        auto res = FromJson(tc.JsonString(), &c);
        EXPECT_TRUE(res.IsOK());
        tc.Expected(c);
    }

    {
        auto tc = TestCase_A_0();
        auto res = FromJson.New<A>(tc.JsonString());
        EXPECT_TRUE(res.IsOK());
        A a = std::move(res.Value());
        tc.Expected(a);
    }

    {
        auto tc = TestCase_A_0();
        auto res = FromJson.New<C>(tc.JsonString());
        EXPECT_TRUE(res.IsOK());
        C c = std::move(res.Value());
        tc.Expected(c);
    }
}

TEST_F(FromJsonTest, from_json_b_and_d_test) {
    {
        auto tc = TestCase_B_0();
        B b;
        auto res = FromJson(tc.JsonString(), &b);
        EXPECT_TRUE(res.IsOK());
        tc.Expected(b.a);
    }

    {
        auto tc = TestCase_B_0();
        D d;
        auto res = FromJson(tc.JsonString(), &d);
        EXPECT_TRUE(res.IsOK());
        tc.Expected(d.c);
    }
}

TEST_F(FromJsonTest, from_json_required_test) {
    {
        E e;

        std::string json_string = R"(
{
    "b": 3
}
        )";

        auto res = FromJson(json_string, &e);
        EXPECT_EQ(res.Message(), std::string("a not found"));
    }

    {
        E e;
        std::string json_string = R"(
{
    "a": 1
}
        )";

        auto res = FromJson(json_string, &e);
        EXPECT_TRUE(res.IsOK());

        EXPECT_EQ(e.a, 1);
        EXPECT_EQ(e.b, 2);
    }
}

TEST_F(FromJsonTest, from_json_enum_test) {
    {
        F f;
        std::string json_string = R"(
{
    "e": 1
}
        )";

        auto res = FromJson(json_string, &f);
        EXPECT_TRUE(res.IsOK());

        EXPECT_EQ(f.e, FEnum::B);
    }
}

TEST_F(FromJsonTest, from_json_map_string_t_test) {
    {
        auto tc = TestCase_G_0();

        G g;
        auto res = FromJson(tc.JsonString(), &g);
        EXPECT_TRUE(res.IsOK());

        tc.Expected(g);
    }
}

TEST_F(FromJsonTest, from_json_vector_test) {
    {
        auto tc = TestCase_A_1();
        std::vector<A> a_list;
        auto res = FromJson(tc.JsonString(), &a_list);
        EXPECT_TRUE(res.IsOK());
        EXPECT_EQ(a_list.size(), 2);
        tc.Expected(a_list);
    }
}

TEST_F(FromJsonTest, from_json_map_test) {
    {
        auto tc = TestCase_A_2();

        std::map<std::string, A> map_a;

        auto res = FromJson(tc.JsonString(), &map_a);
        EXPECT_TRUE(res.IsOK());

        tc.Expected(map_a);
    }
}

}  // namespace rapidjson_utility
