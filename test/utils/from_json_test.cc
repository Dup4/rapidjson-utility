#include "gtest/gtest.h"
#include "snapshot/snapshot.h"

#include <limits>

#include "rapidjson_utils/rapidjson_utils.h"

#include "../structs/a.h"
#include "../structs/b.h"
#include "../structs/c.h"
#include "../structs/d.h"

namespace rapidjson::utils {

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

}  // namespace rapidjson::utils
