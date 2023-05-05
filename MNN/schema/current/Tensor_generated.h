// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TENSOR_MNN_H_
#define FLATBUFFERS_GENERATED_TENSOR_MNN_H_


#include "Type_generated.h"

namespace MNN {

struct Blob;
struct BlobT;

struct ListValue;
struct ListValueT;

struct Attribute;
struct AttributeT;

struct NamedAttrList;
struct NamedAttrListT;

inline const flatbuffers::TypeTable *BlobTypeTable();

inline const flatbuffers::TypeTable *ListValueTypeTable();

inline const flatbuffers::TypeTable *AttributeTypeTable();

inline const flatbuffers::TypeTable *NamedAttrListTypeTable();

enum MNN_DATA_FORMAT {
  MNN_DATA_FORMAT_NCHW = 0,
  MNN_DATA_FORMAT_NHWC = 1,
  MNN_DATA_FORMAT_NC4HW4 = 2,
  MNN_DATA_FORMAT_NHWC4 = 3,
  MNN_DATA_FORMAT_UNKNOWN = 4,
  MNN_DATA_FORMAT_MIN = MNN_DATA_FORMAT_NCHW,
  MNN_DATA_FORMAT_MAX = MNN_DATA_FORMAT_UNKNOWN
};

inline const MNN_DATA_FORMAT (&EnumValuesMNN_DATA_FORMAT())[5] {
  static const MNN_DATA_FORMAT values[] = {
    MNN_DATA_FORMAT_NCHW,
    MNN_DATA_FORMAT_NHWC,
    MNN_DATA_FORMAT_NC4HW4,
    MNN_DATA_FORMAT_NHWC4,
    MNN_DATA_FORMAT_UNKNOWN
  };
  return values;
}

inline const char * const *EnumNamesMNN_DATA_FORMAT() {
  static const char * const names[] = {
    "NCHW",
    "NHWC",
    "NC4HW4",
    "NHWC4",
    "UNKNOWN",
    nullptr
  };
  return names;
}

inline const char *EnumNameMNN_DATA_FORMAT(MNN_DATA_FORMAT e) {
  if (e < MNN_DATA_FORMAT_NCHW || e > MNN_DATA_FORMAT_UNKNOWN) return "";
  const size_t index = static_cast<int>(e);
  return EnumNamesMNN_DATA_FORMAT()[index];
}

struct BlobT : public flatbuffers::NativeTable {
  typedef Blob TableType;
  std::vector<int32_t> dims;
  MNN_DATA_FORMAT dataFormat;
  DataType dataType;
  std::vector<uint8_t> uint8s;
  std::vector<int8_t> int8s;
  std::vector<int32_t> int32s;
  std::vector<int64_t> int64s;
  std::vector<float> float32s;
  std::vector<std::string> strings;
  BlobT()
      : dataFormat(MNN_DATA_FORMAT_NCHW),
        dataType(DataType_DT_FLOAT) {
  }
};

struct Blob FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef BlobT NativeTableType;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return BlobTypeTable();
  }
  const flatbuffers::Vector<int32_t> *dims() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(4);
  }
  MNN_DATA_FORMAT dataFormat() const {
    return static_cast<MNN_DATA_FORMAT>(GetField<int8_t>(6, 0));
  }
  DataType dataType() const {
    return static_cast<DataType>(GetField<int32_t>(8, 1));
  }
  const flatbuffers::Vector<uint8_t> *uint8s() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(10);
  }
  const flatbuffers::Vector<int8_t> *int8s() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(12);
  }
  const flatbuffers::Vector<int32_t> *int32s() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(14);
  }
  const flatbuffers::Vector<int64_t> *int64s() const {
    return GetPointer<const flatbuffers::Vector<int64_t> *>(16);
  }
  const flatbuffers::Vector<float> *float32s() const {
    return GetPointer<const flatbuffers::Vector<float> *>(18);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *strings() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(20);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, 4) &&
           verifier.VerifyVector(dims()) &&
           VerifyField<int8_t>(verifier, 6) &&
           VerifyField<int32_t>(verifier, 8) &&
           VerifyOffset(verifier, 10) &&
           verifier.VerifyVector(uint8s()) &&
           VerifyOffset(verifier, 12) &&
           verifier.VerifyVector(int8s()) &&
           VerifyOffset(verifier, 14) &&
           verifier.VerifyVector(int32s()) &&
           VerifyOffset(verifier, 16) &&
           verifier.VerifyVector(int64s()) &&
           VerifyOffset(verifier, 18) &&
           verifier.VerifyVector(float32s()) &&
           VerifyOffset(verifier, 20) &&
           verifier.VerifyVector(strings()) &&
           verifier.VerifyVectorOfStrings(strings()) &&
           verifier.EndTable();
  }
  BlobT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(BlobT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Blob> Pack(flatbuffers::FlatBufferBuilder &_fbb, const BlobT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct BlobBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_dims(flatbuffers::Offset<flatbuffers::Vector<int32_t>> dims) {
    fbb_.AddOffset(4, dims);
  }
  void add_dataFormat(MNN_DATA_FORMAT dataFormat) {
    fbb_.AddElement<int8_t>(6, static_cast<int8_t>(dataFormat), 0);
  }
  void add_dataType(DataType dataType) {
    fbb_.AddElement<int32_t>(8, static_cast<int32_t>(dataType), 1);
  }
  void add_uint8s(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> uint8s) {
    fbb_.AddOffset(10, uint8s);
  }
  void add_int8s(flatbuffers::Offset<flatbuffers::Vector<int8_t>> int8s) {
    fbb_.AddOffset(12, int8s);
  }
  void add_int32s(flatbuffers::Offset<flatbuffers::Vector<int32_t>> int32s) {
    fbb_.AddOffset(14, int32s);
  }
  void add_int64s(flatbuffers::Offset<flatbuffers::Vector<int64_t>> int64s) {
    fbb_.AddOffset(16, int64s);
  }
  void add_float32s(flatbuffers::Offset<flatbuffers::Vector<float>> float32s) {
    fbb_.AddOffset(18, float32s);
  }
  void add_strings(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> strings) {
    fbb_.AddOffset(20, strings);
  }
  explicit BlobBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  BlobBuilder &operator=(const BlobBuilder &);
  flatbuffers::Offset<Blob> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Blob>(end);
    return o;
  }
};

inline flatbuffers::Offset<Blob> CreateBlob(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> dims = 0,
    MNN_DATA_FORMAT dataFormat = MNN_DATA_FORMAT_NCHW,
    DataType dataType = DataType_DT_FLOAT,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> uint8s = 0,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> int8s = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> int32s = 0,
    flatbuffers::Offset<flatbuffers::Vector<int64_t>> int64s = 0,
    flatbuffers::Offset<flatbuffers::Vector<float>> float32s = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> strings = 0) {
  BlobBuilder builder_(_fbb);
  builder_.add_strings(strings);
  builder_.add_float32s(float32s);
  builder_.add_int64s(int64s);
  builder_.add_int32s(int32s);
  builder_.add_int8s(int8s);
  builder_.add_uint8s(uint8s);
  builder_.add_dataType(dataType);
  builder_.add_dims(dims);
  builder_.add_dataFormat(dataFormat);
  return builder_.Finish();
}

flatbuffers::Offset<Blob> CreateBlob(flatbuffers::FlatBufferBuilder &_fbb, const BlobT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct ListValueT : public flatbuffers::NativeTable {
  typedef ListValue TableType;
  std::vector<std::string> s;
  std::vector<int32_t> i;
  std::vector<float> f;
  std::vector<bool> b;
  std::vector<DataType> type;
  ListValueT() {
  }
};

struct ListValue FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ListValueT NativeTableType;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ListValueTypeTable();
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *s() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(4);
  }
  const flatbuffers::Vector<int32_t> *i() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(6);
  }
  const flatbuffers::Vector<float> *f() const {
    return GetPointer<const flatbuffers::Vector<float> *>(8);
  }
  const flatbuffers::Vector<uint8_t> *b() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(10);
  }
  const flatbuffers::Vector<int32_t> *type() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(12);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, 4) &&
           verifier.VerifyVector(s()) &&
           verifier.VerifyVectorOfStrings(s()) &&
           VerifyOffset(verifier, 6) &&
           verifier.VerifyVector(i()) &&
           VerifyOffset(verifier, 8) &&
           verifier.VerifyVector(f()) &&
           VerifyOffset(verifier, 10) &&
           verifier.VerifyVector(b()) &&
           VerifyOffset(verifier, 12) &&
           verifier.VerifyVector(type()) &&
           verifier.EndTable();
  }
  ListValueT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ListValueT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<ListValue> Pack(flatbuffers::FlatBufferBuilder &_fbb, const ListValueT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ListValueBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_s(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> s) {
    fbb_.AddOffset(4, s);
  }
  void add_i(flatbuffers::Offset<flatbuffers::Vector<int32_t>> i) {
    fbb_.AddOffset(6, i);
  }
  void add_f(flatbuffers::Offset<flatbuffers::Vector<float>> f) {
    fbb_.AddOffset(8, f);
  }
  void add_b(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> b) {
    fbb_.AddOffset(10, b);
  }
  void add_type(flatbuffers::Offset<flatbuffers::Vector<int32_t>> type) {
    fbb_.AddOffset(12, type);
  }
  explicit ListValueBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ListValueBuilder &operator=(const ListValueBuilder &);
  flatbuffers::Offset<ListValue> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ListValue>(end);
    return o;
  }
};

inline flatbuffers::Offset<ListValue> CreateListValue(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> s = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> i = 0,
    flatbuffers::Offset<flatbuffers::Vector<float>> f = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> b = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> type = 0) {
  ListValueBuilder builder_(_fbb);
  builder_.add_type(type);
  builder_.add_b(b);
  builder_.add_f(f);
  builder_.add_i(i);
  builder_.add_s(s);
  return builder_.Finish();
}

flatbuffers::Offset<ListValue> CreateListValue(flatbuffers::FlatBufferBuilder &_fbb, const ListValueT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct AttributeT : public flatbuffers::NativeTable {
  typedef Attribute TableType;
  std::string s;
  int32_t i;
  bool b;
  std::string key;
  DataType type;
  float f;
  std::unique_ptr<BlobT> tensor;
  std::unique_ptr<ListValueT> list;
  std::unique_ptr<NamedAttrListT> func;
  AttributeT()
      : i(0),
        b(false),
        type(DataType_DT_INVALID),
        f(0.0f) {
  }
};

struct Attribute FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AttributeT NativeTableType;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return AttributeTypeTable();
  }
  const flatbuffers::String *s() const {
    return GetPointer<const flatbuffers::String *>(4);
  }
  int32_t i() const {
    return GetField<int32_t>(6, 0);
  }
  bool b() const {
    return GetField<uint8_t>(8, 0) != 0;
  }
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(10);
  }
  bool KeyCompareLessThan(const Attribute *o) const {
    return *key() < *o->key();
  }
  int KeyCompareWithValue(const char *val) const {
    return strcmp(key()->c_str(), val);
  }
  DataType type() const {
    return static_cast<DataType>(GetField<int32_t>(12, 0));
  }
  float f() const {
    return GetField<float>(14, 0.0f);
  }
  const Blob *tensor() const {
    return GetPointer<const Blob *>(16);
  }
  const ListValue *list() const {
    return GetPointer<const ListValue *>(18);
  }
  const NamedAttrList *func() const {
    return GetPointer<const NamedAttrList *>(20);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, 4) &&
           verifier.VerifyString(s()) &&
           VerifyField<int32_t>(verifier, 6) &&
           VerifyField<uint8_t>(verifier, 8) &&
           VerifyOffsetRequired(verifier, 10) &&
           verifier.VerifyString(key()) &&
           VerifyField<int32_t>(verifier, 12) &&
           VerifyField<float>(verifier, 14) &&
           VerifyOffset(verifier, 16) &&
           verifier.VerifyTable(tensor()) &&
           VerifyOffset(verifier, 18) &&
           verifier.VerifyTable(list()) &&
           VerifyOffset(verifier, 20) &&
           verifier.VerifyTable(func()) &&
           verifier.EndTable();
  }
  AttributeT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(AttributeT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Attribute> Pack(flatbuffers::FlatBufferBuilder &_fbb, const AttributeT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct AttributeBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_s(flatbuffers::Offset<flatbuffers::String> s) {
    fbb_.AddOffset(4, s);
  }
  void add_i(int32_t i) {
    fbb_.AddElement<int32_t>(6, i, 0);
  }
  void add_b(bool b) {
    fbb_.AddElement<uint8_t>(8, static_cast<uint8_t>(b), 0);
  }
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(10, key);
  }
  void add_type(DataType type) {
    fbb_.AddElement<int32_t>(12, static_cast<int32_t>(type), 0);
  }
  void add_f(float f) {
    fbb_.AddElement<float>(14, f, 0.0f);
  }
  void add_tensor(flatbuffers::Offset<Blob> tensor) {
    fbb_.AddOffset(16, tensor);
  }
  void add_list(flatbuffers::Offset<ListValue> list) {
    fbb_.AddOffset(18, list);
  }
  void add_func(flatbuffers::Offset<NamedAttrList> func) {
    fbb_.AddOffset(20, func);
  }
  explicit AttributeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AttributeBuilder &operator=(const AttributeBuilder &);
  flatbuffers::Offset<Attribute> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Attribute>(end);
    fbb_.Required(o, 10);
    return o;
  }
};

inline flatbuffers::Offset<Attribute> CreateAttribute(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> s = 0,
    int32_t i = 0,
    bool b = false,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    DataType type = DataType_DT_INVALID,
    float f = 0.0f,
    flatbuffers::Offset<Blob> tensor = 0,
    flatbuffers::Offset<ListValue> list = 0,
    flatbuffers::Offset<NamedAttrList> func = 0) {
  AttributeBuilder builder_(_fbb);
  builder_.add_func(func);
  builder_.add_list(list);
  builder_.add_tensor(tensor);
  builder_.add_f(f);
  builder_.add_type(type);
  builder_.add_key(key);
  builder_.add_i(i);
  builder_.add_s(s);
  builder_.add_b(b);
  return builder_.Finish();
}

flatbuffers::Offset<Attribute> CreateAttribute(flatbuffers::FlatBufferBuilder &_fbb, const AttributeT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct NamedAttrListT : public flatbuffers::NativeTable {
  typedef NamedAttrList TableType;
  std::string name;
  std::vector<std::unique_ptr<AttributeT>> attr;
  NamedAttrListT() {
  }
};

struct NamedAttrList FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef NamedAttrListT NativeTableType;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return NamedAttrListTypeTable();
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(4);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Attribute>> *attr() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Attribute>> *>(6);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, 4) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, 6) &&
           verifier.VerifyVector(attr()) &&
           verifier.VerifyVectorOfTables(attr()) &&
           verifier.EndTable();
  }
  NamedAttrListT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(NamedAttrListT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<NamedAttrList> Pack(flatbuffers::FlatBufferBuilder &_fbb, const NamedAttrListT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct NamedAttrListBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(4, name);
  }
  void add_attr(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Attribute>>> attr) {
    fbb_.AddOffset(6, attr);
  }
  explicit NamedAttrListBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NamedAttrListBuilder &operator=(const NamedAttrListBuilder &);
  flatbuffers::Offset<NamedAttrList> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<NamedAttrList>(end);
    return o;
  }
};

inline flatbuffers::Offset<NamedAttrList> CreateNamedAttrList(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Attribute>>> attr = 0) {
  NamedAttrListBuilder builder_(_fbb);
  builder_.add_attr(attr);
  builder_.add_name(name);
  return builder_.Finish();
}

flatbuffers::Offset<NamedAttrList> CreateNamedAttrList(flatbuffers::FlatBufferBuilder &_fbb, const NamedAttrListT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline BlobT *Blob::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new BlobT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Blob::UnPackTo(BlobT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = dims(); if (_e) { _o->dims.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->dims[_i] = _e->Get(_i); } } };
  { auto _e = dataFormat(); _o->dataFormat = _e; };
  { auto _e = dataType(); _o->dataType = _e; };
  { auto _e = uint8s(); if (_e) { _o->uint8s.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->uint8s[_i] = _e->Get(_i); } } };
  { auto _e = int8s(); if (_e) { _o->int8s.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->int8s[_i] = _e->Get(_i); } } };
  { auto _e = int32s(); if (_e) { _o->int32s.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->int32s[_i] = _e->Get(_i); } } };
  { auto _e = int64s(); if (_e) { _o->int64s.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->int64s[_i] = _e->Get(_i); } } };
  { auto _e = float32s(); if (_e) { _o->float32s.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->float32s[_i] = _e->Get(_i); } } };
  { auto _e = strings(); if (_e) { _o->strings.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->strings[_i] = _e->Get(_i)->str(); } } };
}

inline flatbuffers::Offset<Blob> Blob::Pack(flatbuffers::FlatBufferBuilder &_fbb, const BlobT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateBlob(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Blob> CreateBlob(flatbuffers::FlatBufferBuilder &_fbb, const BlobT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const BlobT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _dims = _o->dims.size() ? _fbb.CreateVector(_o->dims) : 0;
  auto _dataFormat = _o->dataFormat;
  auto _dataType = _o->dataType;
  auto _uint8s = _o->uint8s.size() ? _fbb.CreateVector(_o->uint8s) : 0;
  auto _int8s = _o->int8s.size() ? _fbb.CreateVector(_o->int8s) : 0;
  auto _int32s = _o->int32s.size() ? _fbb.CreateVector(_o->int32s) : 0;
  auto _int64s = _o->int64s.size() ? _fbb.CreateVector(_o->int64s) : 0;
  auto _float32s = _o->float32s.size() ? _fbb.CreateVector(_o->float32s) : 0;
  auto _strings = _o->strings.size() ? _fbb.CreateVectorOfStrings(_o->strings) : 0;
  return MNN::CreateBlob(
      _fbb,
      _dims,
      _dataFormat,
      _dataType,
      _uint8s,
      _int8s,
      _int32s,
      _int64s,
      _float32s,
      _strings);
}

inline ListValueT *ListValue::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new ListValueT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void ListValue::UnPackTo(ListValueT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = s(); if (_e) { _o->s.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->s[_i] = _e->Get(_i)->str(); } } };
  { auto _e = i(); if (_e) { _o->i.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->i[_i] = _e->Get(_i); } } };
  { auto _e = f(); if (_e) { _o->f.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->f[_i] = _e->Get(_i); } } };
  { auto _e = b(); if (_e) { _o->b.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->b[_i] = _e->Get(_i) != 0; } } };
  { auto _e = type(); if (_e) { _o->type.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->type[_i] = static_cast<DataType>(_e->Get(_i)); } } };
}

inline flatbuffers::Offset<ListValue> ListValue::Pack(flatbuffers::FlatBufferBuilder &_fbb, const ListValueT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateListValue(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<ListValue> CreateListValue(flatbuffers::FlatBufferBuilder &_fbb, const ListValueT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const ListValueT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _s = _o->s.size() ? _fbb.CreateVectorOfStrings(_o->s) : 0;
  auto _i = _o->i.size() ? _fbb.CreateVector(_o->i) : 0;
  auto _f = _o->f.size() ? _fbb.CreateVector(_o->f) : 0;
  auto _b = _o->b.size() ? _fbb.CreateVector(_o->b) : 0;
  auto _type = _o->type.size() ? _fbb.CreateVectorScalarCast<int32_t>(flatbuffers::data(_o->type), _o->type.size()) : 0;
  return MNN::CreateListValue(
      _fbb,
      _s,
      _i,
      _f,
      _b,
      _type);
}

inline AttributeT *Attribute::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new AttributeT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Attribute::UnPackTo(AttributeT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = s(); if (_e) _o->s = _e->str(); };
  { auto _e = i(); _o->i = _e; };
  { auto _e = b(); _o->b = _e; };
  { auto _e = key(); if (_e) _o->key = _e->str(); };
  { auto _e = type(); _o->type = _e; };
  { auto _e = f(); _o->f = _e; };
  { auto _e = tensor(); if (_e) _o->tensor = std::unique_ptr<BlobT>(_e->UnPack(_resolver)); };
  { auto _e = list(); if (_e) _o->list = std::unique_ptr<ListValueT>(_e->UnPack(_resolver)); };
  { auto _e = func(); if (_e) _o->func = std::unique_ptr<NamedAttrListT>(_e->UnPack(_resolver)); };
}

inline flatbuffers::Offset<Attribute> Attribute::Pack(flatbuffers::FlatBufferBuilder &_fbb, const AttributeT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateAttribute(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Attribute> CreateAttribute(flatbuffers::FlatBufferBuilder &_fbb, const AttributeT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const AttributeT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _s = _o->s.empty() ? 0 : _fbb.CreateString(_o->s);
  auto _i = _o->i;
  auto _b = _o->b;
  auto _key = _fbb.CreateString(_o->key);
  auto _type = _o->type;
  auto _f = _o->f;
  auto _tensor = _o->tensor ? CreateBlob(_fbb, _o->tensor.get(), _rehasher) : 0;
  auto _list = _o->list ? CreateListValue(_fbb, _o->list.get(), _rehasher) : 0;
  auto _func = _o->func ? CreateNamedAttrList(_fbb, _o->func.get(), _rehasher) : 0;
  return MNN::CreateAttribute(
      _fbb,
      _s,
      _i,
      _b,
      _key,
      _type,
      _f,
      _tensor,
      _list,
      _func);
}

inline NamedAttrListT *NamedAttrList::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new NamedAttrListT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void NamedAttrList::UnPackTo(NamedAttrListT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = name(); if (_e) _o->name = _e->str(); };
  { auto _e = attr(); if (_e) { _o->attr.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->attr[_i] = std::unique_ptr<AttributeT>(_e->Get(_i)->UnPack(_resolver)); } } };
}

inline flatbuffers::Offset<NamedAttrList> NamedAttrList::Pack(flatbuffers::FlatBufferBuilder &_fbb, const NamedAttrListT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateNamedAttrList(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<NamedAttrList> CreateNamedAttrList(flatbuffers::FlatBufferBuilder &_fbb, const NamedAttrListT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const NamedAttrListT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _name = _o->name.empty() ? 0 : _fbb.CreateString(_o->name);
  auto _attr = _o->attr.size() ? _fbb.CreateVector<flatbuffers::Offset<Attribute>> (_o->attr.size(), [](size_t i, _VectorArgs *__va) { return CreateAttribute(*__va->__fbb, __va->__o->attr[i].get(), __va->__rehasher); }, &_va ) : 0;
  return MNN::CreateNamedAttrList(
      _fbb,
      _name,
      _attr);
}

inline const flatbuffers::TypeTable *MNN_DATA_FORMATTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_CHAR, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    MNN_DATA_FORMATTypeTable
  };
  static const char * const names[] = {
    "NCHW",
    "NHWC",
    "NC4HW4",
    "NHWC4",
    "UNKNOWN"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_ENUM, 5, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *BlobTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_INT, 1, -1 },
    { flatbuffers::ET_CHAR, 0, 0 },
    { flatbuffers::ET_INT, 0, 1 },
    { flatbuffers::ET_UCHAR, 1, -1 },
    { flatbuffers::ET_CHAR, 1, -1 },
    { flatbuffers::ET_INT, 1, -1 },
    { flatbuffers::ET_LONG, 1, -1 },
    { flatbuffers::ET_FLOAT, 1, -1 },
    { flatbuffers::ET_STRING, 1, -1 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    MNN_DATA_FORMATTypeTable,
    DataTypeTypeTable
  };
  static const char * const names[] = {
    "dims",
    "dataFormat",
    "dataType",
    "uint8s",
    "int8s",
    "int32s",
    "int64s",
    "float32s",
    "strings"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 9, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *ListValueTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_INT, 1, -1 },
    { flatbuffers::ET_FLOAT, 1, -1 },
    { flatbuffers::ET_BOOL, 1, -1 },
    { flatbuffers::ET_INT, 1, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DataTypeTypeTable
  };
  static const char * const names[] = {
    "s",
    "i",
    "f",
    "b",
    "type"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 5, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *AttributeTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_INT, 0, -1 },
    { flatbuffers::ET_BOOL, 0, -1 },
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_INT, 0, 0 },
    { flatbuffers::ET_FLOAT, 0, -1 },
    { flatbuffers::ET_SEQUENCE, 0, 1 },
    { flatbuffers::ET_SEQUENCE, 0, 2 },
    { flatbuffers::ET_SEQUENCE, 0, 3 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    DataTypeTypeTable,
    BlobTypeTable,
    ListValueTypeTable,
    NamedAttrListTypeTable
  };
  static const char * const names[] = {
    "s",
    "i",
    "b",
    "key",
    "type",
    "f",
    "tensor",
    "list",
    "func"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 9, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *NamedAttrListTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_SEQUENCE, 1, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    AttributeTypeTable
  };
  static const char * const names[] = {
    "name",
    "attr"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 2, type_codes, type_refs, nullptr, names
  };
  return &tt;
}

}  // namespace MNN

#endif  // FLATBUFFERS_GENERATED_TENSOR_MNN_H_