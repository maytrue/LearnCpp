#include <iostream>

class ClassNotDestruct {
 public:
  ClassNotDestruct() {
    std::cout << "construct" << std::endl;
  }

  ~ClassNotDestruct() {
    std::cout << "destruct" << std::endl;
  }

  void Print() {
    std::cout << "Hello world" << std::endl;
  }
};

int main(int argc, char* argv[]) {
  char buffer[100];

  ClassNotDestruct* p = new (buffer) ClassNotDestruct();
  p->Print();
  p->~ClassNotDestruct();

  return 0;
}
