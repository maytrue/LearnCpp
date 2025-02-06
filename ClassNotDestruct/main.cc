#include <iostream>

class ClassNotDestruct {
 public:
  ClassNotDestruct() { std::cout << "construct" << std::endl; }

  ClassNotDestruct(const ClassNotDestruct& other) {
    std::cout << "copy construct" << std::endl;
  }

  ClassNotDestruct& operator=(const ClassNotDestruct& other) {
    std::cout << "assign contruct" << std::endl;
    return *this;
  }

  ~ClassNotDestruct() { std::cout << "destruct" << std::endl; }

  void Print() { std::cout << "Hello world" << std::endl; }
};

int main(int argc, char* argv[]) {
  char buffer[100];

  ClassNotDestruct* p = new (buffer) ClassNotDestruct();
  p->Print();
  p->~ClassNotDestruct();

  ClassNotDestruct a;
  ClassNotDestruct b = a;

  a = b;

  return 0;
}
