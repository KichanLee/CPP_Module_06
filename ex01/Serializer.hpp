#ifndef __SERIALIZER_HPP
#define __SERIALIZER_HPP

#include <cstdint>

#include "Data.hpp"

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& rhs);
  Serializer& operator=(const Serializer& rhs);
  virtual ~Serializer();

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif