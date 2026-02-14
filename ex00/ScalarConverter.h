#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <string>

class ScalarConverter {
public:
  virtual void phantom() = 0;
  ScalarConverter();
  ScalarConverter(ScalarConverter const &);
  ScalarConverter &operator=(ScalarConverter const &);
  ~ScalarConverter();
  static void convert(std::string const &);
};

#endif
