#include <iostream>
#include <random>

int main() {
  // 시드 설정
  std::random_device rd;
  std::mt19937 gen(rd());

  // 3개의 값
  int value1 = 1;
  int value2 = 2;
  int value3 = 3;

  // 균일 분포 생성
  std::uniform_int_distribution<int> distribution(1, 3);

  // 무작위로 선택
  int selectedValue = distribution(gen);

  std::cout << "Selected value: " << selectedValue << std::endl;

  return 0;
}
