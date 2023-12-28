#include <iostream>
#include <sigslot/signal.hpp>

void Test() { std::cout << "Test function" << std::endl; }

int main(int argc, char const *argv[]) {
  std::cout << "Hello, world!" << std::endl;

  sigslot::signal<> sig;
  sig.connect(&Test);

  sig();
  return 0;
}
