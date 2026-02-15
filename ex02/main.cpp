#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iostream>
#include <typeinfo>

Base *generate() {
  unsigned int i = static_cast<unsigned int>(std::rand()) % 3;
  switch (i) {
  case 0:
    return new A();
  case 1:
    return new B();
  default:
    return new C();
  }
}

void identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  if (a != NULL) {
    std::cout << "it is A { field2: \'" << a->field2 << "\' } at " << a
              << std::endl;
    return;
  }
  B *b = dynamic_cast<B *>(p);
  if (b != NULL) {
    std::cout << "it is B { field3: " << std::hex << std::showbase << b->field3
              << " } at " << b << std::endl;
    return;
  }
  C *c = dynamic_cast<C *>(p);
  if (c != NULL) {
    std::cout << "it is C { field4: " << std::hex << std::showbase << c->field4
              << " } at " << c << std::endl;
    return;
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "it is A { field2: \'" << a.field2 << "\' } at " << &a
              << std::endl;
    return;
  } catch (std::bad_cast &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    B &b = dynamic_cast<B &>(p);
    std::cout << "it is B { field3: " << std::hex << std::showbase << b.field3
              << " } at " << &b << std::endl;
    return;
  } catch (std::bad_cast &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    C &c = dynamic_cast<C &>(p);
    std::cout << "it is C { field4: " << std::hex << std::showbase << c.field4
              << " } at " << &c << std::endl;
    return;
  } catch (std::bad_cast &e) {
    std::cerr << e.what() << std::endl;
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  Base *ptr = generate();
  std::cout << "ptr at " << ptr << std::endl;
  identify(ptr);
  identify(*ptr);
  delete ptr;
  return 0;
}
