#include <algorithm>
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << std::clamp(42, -1, 1) << std::endl;
  std::cout << std::clamp(-42, -1, 1) << std::endl;
  std::cout << std::clamp(0, -1, 1) << std::endl;
  std::cout << std::clamp(0.5, -1.0, 1.0) << std::endl;

  return 0;
}
