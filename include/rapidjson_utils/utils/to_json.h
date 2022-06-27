#ifndef RAPIDJSON_UTILS_UTILS_TO_JSON_H
#define RAPIDJSON_UTILS_UTILS_TO_JSON_H

#include <string>
#include <type_traits>

#include "rapidjson/document.h"

#include "../internal/result.h"
#include "../internal/result_or.h"
#include "../internal/schema_options.h"
#include "../types_check/index.h"
#include "./get_json_string.h"
#include "./get_pretty_json_string.h"

namespace rapidjson::utils {

namespace internal {

class ToJsonStringClass {
public:
    template <typename T>
    ResultOr<Document> GetDocument(T *t, rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetObject();

        auto res = StructInjectEntrance(t, [&doc, &root_doc, this](auto &&t, auto &&options) -> Result {
            return this->handleObject(t, doc, options, root_doc);
        });

        if (!res.IsOK()) {
            return res;
        }

        return doc;
    }

    template <typename T>
    ResultOr<Document> GetDocument(T *t) const {
        rapidjson::Document root_doc;
        return GetDocument(t, root_doc);
    }

    template <typename T>
    ResultOr<Document> GetDocument(const std::vector<T> *t) const {
        Document doc;
        doc.SetArray();

        for (const T &i : *t) {
            auto res = this->GetDocument(&i, doc);
            if (!res.IsOK()) {
                return res;
            }

            doc.PushBack(std::move(res.Value()), doc.GetAllocator());
        }

        return doc;
    }

    template <typename T>
    ResultOr<std::string> GetPrettyJsonString(T *t) const {
        auto res = GetDocument(t);
        if (!res.IsOK()) {
            return res;
        }

        return ::rapidjson::utils::GetPrettyJsonString(res.Value());
    }

    template <typename T>
    ResultOr<std::string> GetJsonString(T *t) const {
        auto res = GetDocument(t);
        if (!res.IsOK()) {
            return res;
        }

        return ::rapidjson::utils::GetJsonString(res.Value());
    }

    template <typename T>
    ResultOr<std::string> operator()(T *t) const {
        return GetJsonString(t);
    }

private:
    template <typename T, std::enable_if_t<std::is_same_v<bool, std::remove_const_t<T>>, bool> = true, typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetBool(*t);
        return doc;
    }

    template <typename T, std::enable_if_t<std::is_same_v<float, std::remove_const_t<T>>, bool> = true, typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetFloat(*t);
        return doc;
    }

    template <typename T, std::enable_if_t<std::is_same_v<double, std::remove_const_t<T>>, bool> = true, typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetDouble(*t);
        return doc;
    }

    template <typename T,
            std::enable_if_t<std::is_same_v<int, std::remove_const_t<T>> ||
                                     std::is_same_v<int32_t, std::remove_const_t<T>>,
                    bool> = true,
            typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetInt(*t);
        return doc;
    }

    template <typename T,
            std::enable_if_t<std::is_same_v<unsigned int, std::remove_const_t<T>> ||
                                     std::is_same_v<uint32_t, std::remove_const_t<T>>,
                    bool> = true,
            typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetUint(*t);
        return doc;
    }

    template <typename T,
            std::enable_if_t<std::is_same_v<long long, std::remove_const_t<T>> ||
                                     std::is_same_v<int64_t, std::remove_const_t<T>>,
                    bool> = true,
            typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetInt64(*t);
        return doc;
    }

    template <typename T,
            std::enable_if_t<std::is_same_v<unsigned long long, std::remove_const_t<T>> ||
                                     std::is_same_v<uint64_t, std::remove_const_t<T>>,
                    bool> = true,
            typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, [[maybe_unused]] rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetUint64(*t);
        return doc;
    }

    template <typename T, std::enable_if_t<std::is_same_v<std::string, std::remove_const_t<T>>, bool> = true,
            typename F>
    ResultOr<Document> getSubDocument(
            const T *t, [[maybe_unused]] const F &options, rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetString(t->c_str(), t->length(), root_doc.GetAllocator());
        return doc;
    }

    template <typename T, typename F>
    ResultOr<Document> getSubDocument(const std::vector<T> *t, const F &options, rapidjson::Document &root_doc) const {
        rapidjson::Document doc;
        doc.SetArray();

        for (const T &item : *t) {
            auto res = getSubDocument(&item, options, root_doc);
            if (!res.IsOK()) {
                return res;
            }

            doc.PushBack(std::move(res.Value()), root_doc.GetAllocator());
        }

        return doc;
    }

    template <typename T, typename F>
    ResultOr<Document> getSubDocument(std::vector<T> *t, const F &options, rapidjson::Document &root_doc) const {
        return getSubDocument(static_cast<const std::vector<T> *>(t), options, root_doc);
    }

    template <typename T, typename F>
    ResultOr<Document> getSubDocument(
            const std::optional<T> *t, const F &options, rapidjson::Document &root_doc) const {
        if (t->has_value()) {
            return getSubDocument(&t->value(), options, root_doc);
        } else if (options.default_value.has_value()) {
            return getSubDocument(&options.default_value.value(), options, root_doc);
        } else {
            return MemberNotFoundErrorResult(options.key_name + " not found");
        }
    }

    template <typename T, typename F>
    ResultOr<Document> getSubDocument(std::optional<T> *t, const F &options, rapidjson::Document &root_doc) const {
        return getSubDocument(static_cast<const std::optional<T> *>(t), options, root_doc);
    }

    template <typename T, std::enable_if_t<!is_basic_type_v<std::remove_const_t<T>>, bool> = true, typename F>
    ResultOr<Document> getSubDocument(T *t, [[maybe_unused]] const F &options, rapidjson::Document &root_doc) const {
        return GetDocument(t, root_doc);
    }

    template <typename T, typename F>
    Result handleObject(T *t, rapidjson::Document &doc, const F &options, rapidjson::Document &root_doc) const {
        auto sub_document_res = getSubDocument(t, options, root_doc);
        if (!sub_document_res.IsOK()) {
            if (IsMemberNotFoundError(sub_document_res)) {
                return OKResult();
            } else {
                return sub_document_res;
            }
        }

        doc.AddMember(rapidjson::Value(options.key_name.c_str(), root_doc.GetAllocator()).Move(),
                std::move(sub_document_res.Value()), root_doc.GetAllocator());

        return OKResult();
    }
};

}  // namespace internal

static const auto ToJson = internal::ToJsonStringClass();

}  // namespace rapidjson::utils

#endif  // RAPIDJSON_UTILS_UTILS_TO_JSON_H
