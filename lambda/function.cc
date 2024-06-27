#include <functional>
#include <iostream>

// reference https://mp.weixin.qq.com/s/ZaR7A2WGYR4K-XT6eIzvcw

int Add(int x, int y) {
  int result = x + y;
  std::cout << "x + y = " << result << std::endl;
  return result;
}

int main(int argc, char const *argv[]) {
  auto function = std::bind(Add, 1, 2);  // (1)
  function();                            // (2)

  auto fun2 = std::bind_front(Add, 1);  // (3)
  fun2(3);                              // (4)

  return 0;
}
