#include "ScalarConverter.hpp"

#define CHARACTER 1
#define INTEGER 2
#define FLOAT 3
#define DOUBLE 4

void print_impossibe();
bool func_Num(char* endPtr, std::string input) {
  (void)input;
  if (*endPtr != '\0') return (false);
  return (true);
}

bool func_CommaF(char* endPtr) {
  if (*endPtr != '\0') {
    if (strlen(endPtr) == 1)
      return (true);
    else if (*endPtr == 'f' && strlen(endPtr) == 1)
      return (true);
    else if (!strcmp(endPtr, "nan") || !strcmp(endPtr, "inf") ||
             !strcmp(endPtr, "-inf"))
      print_impossibe();
    return (true);
  }
  return (true);
}

bool Check_Arguments(char* endPtr, std::string input) {
  if (*endPtr)
    if (func_Num(endPtr, input) || func_CommaF(endPtr)) return (true);
  return (false);
}

int Check_Scalar(double result, char* endPtr) {
  if (result >= INT_MIN && result <= INT_MAX)
    return (INTEGER);
  else if (func_CommaF(endPtr))
    return (FLOAT);
  else if (result >= 0 && result <= 127)
    return (CHARACTER);
  else
    return (DOUBLE);
}

void Print_Char(char ch, int err_num) {
  if (ch == '\0')
    std::cout << "char : Non displayable\n" << ch << std::endl;
  else if (err_num == 0)
    std::cout << "char :" << ch << std::endl;
  else
    std::cout << "char : impossible\n";
}

void Print_Int(int num, int err_num) {
  if (err_num == 0)
    std::cout << "int :" << num << std::endl;
  else
    std::cout << "int : impossible\n";
}

int Convert_Char(double result, std::string input) {
  if (result == 0 && input.size() == 1) {
    char ch = static_cast<char>(input.at(0));

    return (static_cast<int>(ch));
  }
  char ch = static_cast<char>(result);
  if (result >= 0 && result <= 127)
    Print_Char(ch, 0);
  else
    Print_Char(ch, 1);
  return (result);
}

int Convert_Int(double result) {
  int num = static_cast<int>(result);
  if (result >= INT_MIN && result <= INT_MAX)
    Print_Int(num, 0);
  else
    Print_Int(num, 1);
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

void print_Format(double result, std::string input) {
  result = Convert_Char(result, input);
  Convert_Int(result);
  std::cout << "float :" << std::fixed << std::showpoint << std::setprecision(1)
            << Convert_Float(result) << "f" << std::endl;
  std::cout << "double :" << Convert_Double(result);
}

void print_impossibe() {
  std::cout << "char : impossible" << std::endl;
  std::cout << "int : impossible" << std::endl;
  std::cout << "float : impossible" << std::endl;
  std::cout << "double : impossible" << std::endl;
}

void ScalarConverter::convert(int ac, const char* av[]) {
  if (ac != 2) {
    std::cerr << "Not a Valid Argument\n";
    return;
  }
  char* endPtr = NULL;
  double result = 0;

  result = std::strtod(av[1], &endPtr);
  std::string input(av[1]);
  if (!Check_Arguments(endPtr, input)) return;

  switch (Check_Scalar(result, endPtr)) {
    case CHARACTER:
      print_Format(result, input);
      break;
    case INTEGER:
      print_Format(result, input);
      break;
    case FLOAT:
      print_Format(result, input);
      break;
    case DOUBLE:
      print_Format(result, input);
      break;
    default:
      print_impossibe();
  }
}