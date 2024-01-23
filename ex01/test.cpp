#include <cstdlib>
#include <iostream>

int main() {
  const char* str = "42.0f";  // The string to convert to a long integer

  char*
      endPtr;  // Pointer to the first character after the number in the string
  double result = std::strtod(str, &endPtr);

  if (*endPtr != '\0') {
    std::cerr << "Conversion error: Not a valid integer." << std::endl;
    return 1;
  }
  std::ostringstream oss;
  std::cout << result << std::endl;
  oss << (result);

  // Print the converted value
  std::cout << "Converted value: " << result << std::endl;

  return 0;  // Exit successfully
}
