#include "Serializer.h"
#include <ios>
#include <iostream>

int main() {
  Data *ptr = new Data();
  std::cout << "Data *ptr = " << ptr << std::endl;
  uintptr_t p = Serializer::serialize(ptr);
  std::cout << "uintptr_t: " << std::hex << std::showbase << p << std::endl;
  Data *ptr2 = Serializer::deserialize(p);
  std::cout << "Data *: " << ptr2 << std::endl;
  delete ptr;
  return 0;
}
