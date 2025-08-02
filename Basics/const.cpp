#include <iostream>

int main() {
  // a fixed value which cannot be changed once initialized
  const float PI = 3.141525;

  // an expression which can be evaluated at compile time
  // and acts like const at runtime
  constexpr int expression = 3 + 5 + 9;

  std::cout << PI << std::endl;
  std::cout << expression << std::endl;

  // check for is const
  std::cout << std::is_const<decltype(PI)>::value << std::endl;  // 1
  std::cout << std::is_const_v<const int> << std::endl;          // 1
  std::cout << std::is_const_v<bool> << std::endl;               // 0

  return 0;
}