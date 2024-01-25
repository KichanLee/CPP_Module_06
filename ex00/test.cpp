
#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

float Convert_Float(double result) {
  float f_num = static_cast<float>(result);

  return (f_num);
}

int main() {
  double a = 20.0;

  //   std::cout << std::fixed << std::showpoint << std::setprecision(1) << a <<
  //   "f"
  //             << std::endl;
  std::cout << std::fixed << std::showpoint << a << "f" << std::endl;
}
