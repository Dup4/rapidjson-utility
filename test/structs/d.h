#pragma once

#include "./c.h"

#include "rapidjson_utils/rapidjson_utils.h"

namespace rapidjson::utils {

struct D {
    C c;
};

RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_BEGIN(D)
RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_FIELD(c, SchemaOptionsBuilder.WithKeyName("a"))
RAPIDJSON_UTILS_EXTERNAL_STRUCT_SCHEMA_DECLARE_END

}  // namespace rapidjson::utils
