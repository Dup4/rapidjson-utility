#include <benchmark/benchmark.h>

#include "rapidjson_utility/rapidjson_utility.h"

#include "../structs/a.h"

using namespace rapidjson_utility;

static void BenchmarkFromJson_A(benchmark::State& state) {
    auto tc = TestCase_A_0();

    for (auto _ : state) {
        A a;
        auto res = FromJson(tc.JsonString(), &a);
    }
}

BENCHMARK(BenchmarkFromJson_A);
