// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "json_serializer.h"

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>

namespace {

struct NullDeserializer : public dap::Deserializer {
  static NullDeserializer instance;

  bool deserialize(dap::boolean*) const override { return false; }
  bool deserialize(dap::integer*) const override { return false; }
  bool deserialize(dap::number*) const override { return false; }
  bool deserialize(dap::string*) const override { return false; }
  bool deserialize(dap::object*) const override { return false; }
  bool deserialize(dap::any*) const override { return false; }
  size_t count() const override { return 0; }
  bool array(const std::function<bool(dap::Deserializer*)>&) const override {
    return false;
  }
  bool field(const std::string&,
             const std::function<bool(dap::Deserializer*)>&) const override {
    return false;
  }
};

NullDeserializer NullDeserializer::instance;

}  // anonymous namespace

namespace dap {
namespace json {

Deserializer::Deserializer(const std::string& str)
    : doc(new rapidjson::Document()), ownsJson(true) {
  doc->Parse(str);
}

Deserializer::Deserializer(rapidjson::Value* json)
    : val(json), ownsJson(false) {}

Deserializer::~Deserializer() {
  if (ownsJson) {
    delete doc;
  }
}

bool Deserializer::deserialize(dap::boolean* v) const {
  if (!json()->IsBool()) {
    return false;
  }
  *v = json()->GetBool();
  return true;
}

bool Deserializer::deserialize(dap::integer* v) const {
  if (!json()->IsInt()) {
    return false;
  }
  *v = json()->GetInt();
  return true;
}

bool Deserializer::deserialize(dap::number* v) const {
  if (!json()->IsNumber()) {
    return false;
  }
  *v = json()->GetDouble();
  return true;
}

bool Deserializer::deserialize(dap::string* v) const {
  if (!json()->IsString()) {
    return false;
  }
  *v = json()->GetString();
  return true;
}

bool Deserializer::deserialize(dap::object* v) const {
  v->reserve(json()->MemberCount());
  for (auto el = json()->MemberBegin(); el != json()->MemberEnd(); el++) {
    dap::any val;
    Deserializer d(&(el->value));
    if (!d.deserialize(&val)) {
      return false;
    }
    (*v)[el->name.GetString()] = val;
  }
  return true;
}

bool Deserializer::deserialize(dap::any* v) const {
  if (json()->IsBool()) {
    *v = dap::boolean(json()->GetBool());
  } else if (json()->IsDouble()) {
    *v = dap::number(json()->GetDouble());
  } else if (json()->IsInt()) {
    *v = dap::integer(json()->GetInt());
  } else if (json()->IsString()) {
    *v = dap::string(json()->GetString());
  } else if (json()->IsNull()) {
    *v = null();
  } else {
    return false;
  }
  return true;
}

size_t Deserializer::count() const {
  return json()->Size();
}

bool Deserializer::array(
    const std::function<bool(dap::Deserializer*)>& cb) const {
  if (!json()->IsArray()) {
    return false;
  }
  for (uint32_t i = 0; i < json()->Size(); i++) {
    Deserializer d(&(*json())[i]);
    if (!cb(&d)) {
      return false;
    }
  }
  return true;
}

bool Deserializer::field(
    const std::string& name,
    const std::function<bool(dap::Deserializer*)>& cb) const {
  if (!json()->IsObject()) {
    return false;
  }
  auto it = json()->FindMember(name);
  if (it == json()->MemberEnd()) {
    return cb(&NullDeserializer::instance);
  }
  Deserializer d(&(it->value));
  return cb(&d);
}

Serializer::Serializer()
    : doc(new rapidjson::Document(rapidjson::kObjectType)),
      allocator(doc->GetAllocator()),
      ownsJson(true) {}

Serializer::Serializer(rapidjson::Value* json,
                       rapidjson::Document::AllocatorType& allocator)
    : val(json), allocator(allocator), ownsJson(false) {}

Serializer::~Serializer() {
  if (ownsJson) {
    delete doc;
  }
}

std::string Serializer::dump() const {
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  json()->Accept(writer);
  return sb.GetString();
}

bool Serializer::serialize(dap::boolean v) {
  json()->SetBool(v);
  return true;
}

bool Serializer::serialize(dap::integer v) {
  json()->SetInt64(v);
  return true;
}

bool Serializer::serialize(dap::number v) {
  json()->SetDouble(v);
  return true;
}

bool Serializer::serialize(const dap::string& v) {
  json()->SetString(v.data(), static_cast<uint32_t>(v.length()), allocator);
  return true;
}

bool Serializer::serialize(const dap::object& v) {
  if (!json()->IsObject()) {
    json()->SetObject();
  }
  for (auto& it : v) {
    if (!json()->HasMember(it.first.c_str())) {
      rapidjson::Value name_value{it.first.c_str(), allocator};
      json()->AddMember(name_value, rapidjson::Value(), allocator);
    }
    rapidjson::Value& member = (*json())[it.first.c_str()];
    Serializer s(&member, allocator);
    if (!s.serialize(it.second)) {
      return false;
    }
  }
  return true;
}

bool Serializer::serialize(const dap::any& v) {
  if (v.is<dap::boolean>()) {
    json()->SetBool((bool)v.get<dap::boolean>());
  } else if (v.is<dap::integer>()) {
    json()->SetInt((int)v.get<dap::integer>());
  } else if (v.is<dap::number>()) {
    json()->SetDouble((double)v.get<dap::number>());
  } else if (v.is<dap::string>()) {
    auto s = v.get<dap::string>();
    json()->SetString(s.data(), static_cast<uint32_t>(s.length()));
  } else if (v.is<dap::null>()) {
  } else {
    return false;
  }

  return true;
}

bool Serializer::array(size_t count,
                       const std::function<bool(dap::Serializer*)>& cb) {
  if (!json()->IsArray()) {
    json()->SetArray();
  }

  while (count > json()->Size()) {
    json()->PushBack(rapidjson::Value(), allocator);
  }

  for (uint32_t i = 0; i < count; i++) {
    Serializer s(&(*json())[i], allocator);
    if (!cb(&s)) {
      return false;
    }
  }
  return true;
}

bool Serializer::object(const std::function<bool(dap::FieldSerializer*)>& cb) {
  struct FS : public FieldSerializer {
    rapidjson::Value* const json;
    rapidjson::Document::AllocatorType& allocator;

    FS(rapidjson::Value* json, rapidjson::Document::AllocatorType& allocator)
        : json(json), allocator(allocator) {}
    bool field(const std::string& name, const SerializeFunc& cb) override {
      if (!json->HasMember(name.c_str())) {
        rapidjson::Value name_value{name.c_str(), allocator};
        json->AddMember(name_value, rapidjson::Value(), allocator);
      }
      rapidjson::Value& member = (*json)[name.c_str()];
      Serializer s(&member, allocator);
      auto res = cb(&s);
      if (s.removed) {
        json->RemoveMember(name.c_str());
      }
      return res;
    }
  };

  if (!json()->IsObject()) {
    json()->SetObject();
  }
  FS fs{json(), allocator};
  return cb(&fs);
}

void Serializer::remove() {
  removed = true;
}

}  // namespace json
}  // namespace dap
