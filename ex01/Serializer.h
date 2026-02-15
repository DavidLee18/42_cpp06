#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>

typedef unsigned long uintptr_t;

class Data {
  std::string dummy;

public:
  Data();
  Data(Data const &);
  Data &operator=(Data const &);
  ~Data();
};

class Serializer {
  virtual void phantom() = 0;

public:
  static uintptr_t serialize(Data *);
  static Data *deserialize(uintptr_t);
};

#endif
