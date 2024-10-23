#include <iostream>

class Cat {
 public:
  Cat(const std::string& name, const std::string& color, int weight) {
    std::cout << "Cat name:" << name << ", color:" << color
              << ", weight:" << weight << std::endl;
  }
};

class Dog {
 public:
  Dog(const std::string& name, int age) {
    std::cout << "Dog name:" << name << ", age:" << age << std::endl;
  }
};

template <class T, class... Args>
T* CreateObject(Args... args) {
  return new T(std::forward<Args>(args)...);
}

int main(int argc, char const* argv[]) {
  auto my_cat = CreateObject<Cat>("hellokitty", "block", 20);
  auto my_dog = CreateObject<Dog>("turkey", 2);

  return 0;
}
