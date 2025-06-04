#include <iostream>
#include <memory>

#include <sigslot/signal.hpp>

void Test() { std::cout << "Test function" << std::endl; }

class Hello {
public:
  void Print() {
    std::cout << "hello world" << std::endl;
  }
};

class Test1 {
public:
  Test1() {
    std::cout << "Test1 construct" << std::endl;
  }

  ~Test1() {
    std::cout << "~Test1 deconstruct" << std::endl;
  }

  void Print() {
    std::cout << "Test1 Print" << std::endl;
  }

private:
  void Test() {
    std::cout << "Test1 Test" << std::endl;
  }
};

int main(int argc, char const *argv[]) {

  sigslot::signal<> sig;
  std::cout << "----- new triger ------" << std::endl;
  sig.connect(&Test);
  sig();

  std::cout << "----- new triger ------" << std::endl;
  Hello hi;
  sig.connect(&Hello::Print, &hi);
  sig();

  std::cout << "----- new triger ------" << std::endl;
  sig.disconnect(&Test);
  sig();

  std::cout << "----- new triger ------" << std::endl;
  auto t1 = std::make_shared<Test1>();
  sig.connect(&Test1::Print, t1);
  sig();

  std::cout << "----- new triger ------" << std::endl;
  t1.reset();
  sig();

  return 0;
}
