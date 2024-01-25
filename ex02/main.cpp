#include <iostream>
#include <random>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
  A a;
  B b;
  C c;
  Base base;
  Base* bp = generate();
  identify(bp);
  A& a_ref = a;
  B& b_ref = b;
  C& c_ref = c;
  identify(dynamic_cast<Base&>(a_ref));
  identify(dynamic_cast<Base&>(b_ref));
  identify(dynamic_cast<Base&>(c_ref));
}

Base* generate(void) {
  Base* re_ptr;

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> distribution(1, 3);

  int selectedValue = distribution(gen);

  if (selectedValue == 1) {
    A a;
    re_ptr = &a;
  } else if (selectedValue == 2) {
    B b;
    re_ptr = &b;
  } else {
    C c;
    re_ptr = &c;
  }
  return (re_ptr);
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A class" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B class" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C class" << std::endl;
  else
    std::cout << "Not in A, B, C class\n";
}

void identify(Base& p) {
  try {
    A a = dynamic_cast<A&>(p);
    std::cout << "A class\n";
  } catch (const std::exception& e) {
    try {
      B b = dynamic_cast<B&>(p);
      std::cout << "B class\n";
    } catch (const std::exception& e) {
      try {
        C c = dynamic_cast<C&>(p);
        std::cout << "C class\n";
      } catch (const std::exception& e) {
        std::cout << "Not in A, B, C class\n";
        std::cerr << e.what() << '\n';
      }
    }
  }
}
