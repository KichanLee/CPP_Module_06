#include <cstdlib>
#include <iostream>

int main() {
  const char* str = "123234.f";  // 부동 소수점 값을 포함하는 문자열
  int base;
  // strtod 함수를 사용하여 문자열을 double 값으로 변환
  char* endPtr;  // 변환 후 문자열의 끝 위치를 나타내는 포인터
  double result = std::strtol(str, &endPtr, base);

  // 변환 결과 출력
  std::cout << "Converted value: " << result << std::endl;

  // 변환 후 문자열의 나머지 부분 출력 (이 부분은 숫자가 아닌 문자를 포함할 수
  // 있음)
  std::cout << "Remaining string: " << endPtr << std::endl;
  std::cout << "Base: " << base << std::endl;

  return 0;
}
