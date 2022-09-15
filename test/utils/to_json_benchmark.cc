#include <benchmark/benchmark.h>

#include "rapidjson-utility/rapidjson-utility.h"

#include "../structs/a.h"

using namespace rapidjson_utility;

static void BenchmarkToJson_A(benchmark::State& state) {
    auto tc = TestCase_A_0();
    const A a = tc.Instance();

    for (auto _ : state) {
        auto res = ToJson(&a);
    }
}

BENCHMARK(BenchmarkToJson_A);
