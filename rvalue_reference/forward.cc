#include <iostream>

void func(int& i) { std::cout << "int& called" << std::endl; }

void func(int&& i) { std::cout << "int&& called" << std::endl; }

void func(const int& i) { std::cout << "const int& called" << std::endl; }

template <typename T>
void forwarder(T&& arg) {
  func(std::forward<T>(arg));
}

int main(int argc, char const* argv[]) {
  const int i = 10;
  forwarder(i);

  forwarder(10);
  return 0;
}
