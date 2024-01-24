#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
  uintptr_t ut = reinterpret_cast<uintptr_t>(ptr);

  return (ut);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}