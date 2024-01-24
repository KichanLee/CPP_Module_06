#include "Serializer.hpp"

int main() {
  Data person;
  person._age = 42;

  uintptr_t person_ptr = Serializer::serialize(&person);

  std::cout << "person data : " << person._age << std::endl;

  std::cout << "person address : " << &person << std::endl;

  std::cout << "person_ptr address : " << person_ptr << std::endl;

  std::cout << "person_ptr address :" << Serializer::deserialize(person_ptr)
            << std::endl;
  std::cout << "person data : " << person._age << std::endl;
}