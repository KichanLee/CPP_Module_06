#include <iostream>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
  A a;
  B b;
  C c;
  int value1 = 1;
  int value2 = 2;
  int value3 = 3;
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> distribution(1, 3);

  int selectedValue = distribution(gen);

  std::cout << "Selected value: " << selectedValue << std::endl;

  if (selectedValue == 1)
    return (&a);
  else if (selectedValue == 2)
    return (&b);
  else
    return (&c);
}
void identify(Base* p) {}
void identify(Base& p) {}

int main() {}
