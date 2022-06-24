#ifndef RAPIDJSON_UTILS_GET_JSON_STRING_H
#define RAPIDJSON_UTILS_GET_JSON_STRING_H

#include <string>

#include "rapidjson/document.h"
#include "rapidjson/error/error.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

namespace rapidjson::utils {

namespace internal {

class GetJsonStringClass {
public:
    std::string operator()(const Document &doc) const {
        auto buffer = StringBuffer();
        auto pretty_writer = Writer<StringBuffer>(buffer);
        doc.Accept(pretty_writer);

        return std::string(buffer.GetString());
    }
};

}  // namespace internal

static const auto GetJsonString = internal::GetJsonStringClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_GET_JSON_STRING_H
