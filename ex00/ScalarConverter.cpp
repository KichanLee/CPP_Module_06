#include "ScalarConverter.hpp"

#define CHARACTER 1
#define INTEGER 2
#define FLOAT 3
#define DOUBLE 4

bool func_Num(char* endPtr) {
  if (*endPtr != '\0') return (false);
  return (true);
}

bool func_CommaF(char* endPtr) {
  if (*endPtr != '\0') {
    if (strlen(endPtr) == 1 && 'a' <= *endPtr && 'z' >= *endPtr) return (true);
    if (*endPtr == 'f' && strlen(endPtr) == 1) return (true);
    return (false);
  }
  return (true);
}

bool Check_Arguments(char* endPtr) {
  if (func_Num(endPtr) || func_CommaF(endPtr)) return (true);
  return (false);
}

int Check_Scalar(double result, char* endPtr) {
  if (result > INT_MIN || result < INT_MAX)
    return (INTEGER);
  else if (func_CommaF(endPtr))
    return (FLOAT);
  else if (result >= 0 && result <= 127)
    return (CHARACTER);
  else
    return (DOUBLE);
}

char Convert_Char(double result) {
  char ch = static_cast<char>(result);

  return (ch);
}
int Convert_Int(double result) {
  int num = static_cast<int>(result);
  return (num);
}
float Convert_Float(double result) {
  float f_num = static_cast<float>(result);

  return (f_num);
}
double Convert_Double(double result) {
  double d_num = static_cast<double>(result);

  return (d_num);
}

void ScalarConverter::convert(int ac, const char* av[]) {
  if (ac != 2) return;
  char* endPtr = NULL;
  double result = 0;

  result = std::strtod(av[1], &endPtr);
  if (!Check_Arguments(endPtr)) return;

  std::cout << "Sclar Type : " << Check_Scalar(result, endPtr) << std::endl;
  switch (Check_Scalar(result, endPtr)) {
    case CHARACTER:
      std::cout << "char :" << Convert_Char(result) << std::endl;
      std::cout << "int :" << Convert_Int(result) << std::endl;
      std::cout << "float :" << Convert_Float(result) << std::showpoint
                << std::fixed << std::setprecision(1) << std::endl;
      std::cout << "double :" << Convert_Double(result) << std::showpoint
                << std::endl;
      std::setprecision(1);

      break;
    case INTEGER:
      std::cout << "char :" << Convert_Char(result) << std::endl;
      std::cout << "int :" << Convert_Int(result) << std::endl;
      std::cout << "float :" << Convert_Float(result) << std::showpoint
                << std::fixed << std::setprecision(1) << std::endl;
      std::cout << "double :" << Convert_Double(result) << std::showpoint
                << std::endl;
      std::setprecision(1);

      break;

    case FLOAT:
      std::cout << "char :" << Convert_Char(result) << std::endl;
      std::cout << "int :" << Convert_Int(result) << std::endl;
      std::cout << "float :" << Convert_Float(result) << std::showpoint
                << std::fixed << std::setprecision(1) << std::endl;
      std::cout << "double :" << Convert_Double(result) << std::showpoint
                << std::endl;
      std::setprecision(1);

      std::cout << std::showpoint << std::fixed << std::setprecision(1);
      break;
    case DOUBLE:
      std::cout << "char :" << Convert_Char(result) << std::endl;
      std::cout << "int :" << Convert_Int(result) << std::endl;
      std::cout << "float :" << Convert_Float(result) << std::showpoint
                << std::fixed << std::setprecision(1) << std::endl;
      std::cout << "double :" << Convert_Double(result) << std::showpoint
                << std::endl;
      std::setprecision(1);

      break;
  }
}
