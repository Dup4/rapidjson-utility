#pragma once

#include "rapidjson-utility/rapidjson-utility.h"

namespace rapidjson_utility {

enum class FEnum : int {
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
};

struct F {
    FEnum e;

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_BEGIN(F)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(e)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_END
};

}  // namespace rapidjson_utility
