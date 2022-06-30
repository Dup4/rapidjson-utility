#ifndef RAPIDJSON_UTILITY_UTILITY_GET_JSON_STRING_H
#define RAPIDJSON_UTILITY_UTILITY_GET_JSON_STRING_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

namespace rapidjson_utility {

namespace internal {

class GetJsonStringClass {
public:
    std::string operator()(const rapidjson::Document &doc) const {
        auto buffer = rapidjson::StringBuffer();
        auto pretty_writer = rapidjson::Writer<rapidjson::StringBuffer>(buffer);
        doc.Accept(pretty_writer);

        return std::string(buffer.GetString());
    }
};

}  // namespace internal

static const auto GetJsonString = internal::GetJsonStringClass();

}  // namespace rapidjson_utility

#endif  // RAPIDJSON_UTILITY_UTILITY_GET_JSON_STRING_H
