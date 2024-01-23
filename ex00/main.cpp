#include <cstdlib>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int ac, const char* av[]) {
  ScalarConverter::convert(ac, av);
  // const char* str = "41.asdfasdf";  // 정수 값을 포함하는 문자열

  // // strtol 함수를 사용하여 문자열을 long int 값으로 변환
  // char* endPtr;  // 변환 후 문자열의 끝 위치를 나타내는 포인터
  // long int result = std::strtol(str, &endPtr, 10);

  // // 변환 결과 출력
  // std::cout << "Converted value: " << result << std::endl;

  // // 변환 후 문자열의 나머지 부분 출력 (이 부분은 숫자가 아닌 문자를 포함할
  // 수
  // // 있음)
  // std::cout << "Remaining string: " << endPtr << std::endl;

  return 0;
}
