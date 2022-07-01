#pragma once

#include "rapidjson_utility/rapidjson_utility.h"

#include <map>
#include <string>

#include "./a.h"

namespace rapidjson_utility {

struct G {
    std::map<std::string, A> map_a;

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_BEGIN(G)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(map_a)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_END
};

}  // namespace rapidjson_utility
