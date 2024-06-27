#include <iostream>

void Foo(int x) { std::cout << "Funcation called with " << x << std::endl; }

void Bar(void (*f)(int), int value) { f(value); }

struct Functor {
  void operator()(int x) {
    std::cout << "Functor called with " << x << std::endl;
  }
};

int main(int argc, char const *argv[]) {
  Bar(Foo, 10);

  Functor functor;
  functor(20);

  return 0;
}
