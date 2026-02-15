#include "ScalarConverter.h"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &lit) {
  LIT_TYPE ty = UNKNOWN;
  double val;
  if (lit.length() == 3 && lit[0] == '\'' && lit[2] == '\'')
    ty = CHAR, val = static_cast<double>(lit[1]);
  else if (lit.length() == 1 && std::isdigit(lit[0]))
    ty = INT, val = lit[0] - '0';
  else if (lit.length() > 1) {
    const char *ptr = lit.c_str();
    val = std::strtod(lit.c_str(), const_cast<char **>(&ptr));
    if (*ptr == 'f' && *(ptr + 1) == '\0')
      ty = FLOAT;
    else if (*ptr == '\0') {
      ty = DOUBLE;
      if (val - static_cast<int>(val) == 0)
        ty = INT;
    }
  }
  if (ty == UNKNOWN) {
    std::cerr << "unknown literal \"" << lit << "\"" << std::endl;
    std::exit(1);
  } else if (ty == CHAR) {
    std::cout << "this is char literal";
    if (!std::isprint(static_cast<int>(val)))
      std::cout << ", yet it\'s not displayable. ascii code: "
                << static_cast<int>(val) << '.' << std::endl;
    else
      std::cout << ", and it is \'" << static_cast<char>(val) << "\'."
                << std::endl;
    std::cout << "as int: " << static_cast<int>(val) << std::endl;
    std::cout << "as float: "
              << std::setprecision(std::numeric_limits<float>::digits10)
              << static_cast<float>(val) << 'f' << std::endl;
    std::cout << "as double: "
              << std::setprecision(std::numeric_limits<double>::digits10) << val
              << std::endl;
  } else if (ty == INT) {
    std::cout << "this is int literal, which is " << static_cast<int>(val)
              << '.' << std::endl;
    std::cout << "as char: ";
    if (!std::isprint(static_cast<int>(val)))
      std::cout << "<non-displayable>" << std::endl;
    else
      std::cout << '\'' << static_cast<char>(val) << '\'' << std::endl;
    std::cout << "as float: "
              << std::setprecision(std::numeric_limits<float>::digits10)
              << static_cast<float>(val) << 'f' << std::endl;
    std::cout << "as double: "
              << std::setprecision(std::numeric_limits<double>::digits10) << val
              << std::endl;
  } else if (ty == FLOAT) {
    std::cout << "this is float literal, which is "
              << std::setprecision(std::numeric_limits<float>::digits10)
              << static_cast<float>(val) << "f." << std::endl;
    std::cout << "as char: ";
    if (std::fabs(val) == std::numeric_limits<double>::infinity() ||
        val != val) {
      std::cout << "<impossible>" << std::endl;
      std::cout << "as int: <impossible>" << std::endl;
      std::cout << "as double: "
                << std::setprecision(std::numeric_limits<double>::digits10)
                << val << std::endl;
    } else {
      if (!std::isprint(static_cast<int>(val)))
        std::cout << "<non-displayable>" << std::endl;
      else
        std::cout << '\'' << static_cast<char>(val) << '\'' << std::endl;
      std::cout << "as int: " << static_cast<int>(val) << std::endl;
      std::cout << "as double: "
                << std::setprecision(std::numeric_limits<double>::digits10)
                << val << std::endl;
    }
  } else {
    std::cout << "this is double literal, which is "
              << std::setprecision(std::numeric_limits<double>::digits10) << val
              << '.' << std::endl;
    std::cout << "as char: ";

    if (std::fabs(val) == std::numeric_limits<double>::infinity() ||
        val != val) {
      std::cout << "<impossible>" << std::endl;
      std::cout << "as int: <impossible>" << std::endl;
      std::cout << "as float: "
                << std::setprecision(std::numeric_limits<float>::digits10)
                << val << std::endl;
    } else {
      if (!std::isprint(static_cast<int>(val)))
        std::cout << "<non-displayable>" << std::endl;
      else
        std::cout << '\'' << static_cast<char>(val) << '\'' << std::endl;
      std::cout << "as int: " << static_cast<int>(val) << std::endl;
      std::cout << "as float: "
                << std::setprecision(std::numeric_limits<float>::digits10)
                << static_cast<float>(val) << 'f' << std::endl;
    }
  }
}
