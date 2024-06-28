#include <iostream>
#include <memory>

class Obj {
 public:
  Obj() { std::cout << "Obj()" << std::endl; }
  Obj(const Obj& obj) { std::cout << "Obj(const Obj& obj)" << std::endl; }
  Obj(Obj&& obj) { std::cout << "Obj(Obj&& obj)" << std::endl; }
  ~Obj() { std::cout << "~Obj()" << std::endl; }

  void Fun() { std::cout << "Fun()" << std::endl; }
};

int main(int argc, char const* argv[]) {
  auto p1 = std::make_unique<Obj>();
  auto p2 = std::move(p1);

  if (p1) {
    std::cout << "p1 is valid" << std::endl;
  } else {
    std::cout << "p1 is invalid ptr:" << p1.get() << std::endl;
  }
  p2->Fun();
  return 0;
}
