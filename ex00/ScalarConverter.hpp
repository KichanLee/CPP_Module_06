#ifndef __SCALARCONVETER_HPP
#define __SCALARCONVETER_HPP

#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& rhs);
  ScalarConverter& operator=(const ScalarConverter& rhs);

 public:
  static void convert(int ac, const char* av[]);
};

#endif