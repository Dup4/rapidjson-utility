#pragma once

#include "rapidjson-utility/rapidjson-utility.h"

#include <map>
#include <optional>
#include <string>

namespace rapidjson_utility {

struct H {
    int a;
    std::optional<int> b;

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_BEGIN(H)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(a)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(b)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_END
};

}  // namespace rapidjson_utility
