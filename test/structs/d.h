#pragma once

#include "./c.h"

#include "rapidjson-utility/rapidjson-utility.h"

namespace rapidjson_utility {

struct D {
    C c;
};

RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_BEGIN(D)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(c, SchemaOptions::WithKeyName("a"))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_END

}  // namespace rapidjson_utility
