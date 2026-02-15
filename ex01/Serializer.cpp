#include "Serializer.h"

Data::Data() : dummy() {}

Data::Data(Data const &other) : dummy(other.dummy) {}

Data &Data::operator=(Data const &other) {
  dummy = other.dummy;
  return *this;
}

Data::~Data() {}

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
