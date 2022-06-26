#pragma once

#include "./a.h"

#include "rapidjson_utils/rapidjson_utils.h"

namespace rapidjson::utils {

struct B {
    A a;

    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_BEGIN(B)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_FIELD(a)
    RAPIDJSON_UTILS_STRUCT_SCHEMA_DECLARE_END
};

}  // namespace rapidjson::utils
