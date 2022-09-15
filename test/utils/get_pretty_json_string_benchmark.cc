#include "benchmark/benchmark.h"

#include <string>

#include "rapidjson-utility/rapidjson-utility.h"

using namespace rapidjson;
using namespace rapidjson_utility;

static void BenchmarkGetPrettyJsonString(benchmark::State& state) {
    std::string json_string = "[";

    for (int i = 0; i < state.range(0); ++i) {
        json_string += "1";
        if (i != state.range(0) - 1) {
            json_string += ",";
        }
    }

    json_string += "]";

    for (auto _ : state) {
        auto res = GetPrettyJsonString(json_string);
        assert(res.IsOK());
    }
}

BENCHMARK(BenchmarkGetPrettyJsonString)->Arg(1)->Arg(10)->Arg(100)->Arg(1000)->Arg(10000);
