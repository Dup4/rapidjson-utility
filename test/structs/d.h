#pragma once

#include "./c.h"

#include "rapidjson_utility/rapidjson_utility.h"

namespace rapidjson::utility {

struct D {
    C c;
};

RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_BEGIN(D)
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(c, SchemaOptionsBuilder.WithKeyName("a"))
RAPIDJSON_UTILITY_EXTERNAL_STRUCT_SCHEMA_DECLARE_END

}  // namespace rapidjson::utility
