#pragma once

#include "rapidjson-utility/rapidjson-utility.h"

namespace rapidjson_utility {

struct E {
    int a;
    int b{2};

    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_BEGIN(E)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(a, SchemaOptions::WithRequired())
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_FIELD(b)
    RAPIDJSON_UTILITY_STRUCT_SCHEMA_DECLARE_END
};

}  // namespace rapidjson_utility
