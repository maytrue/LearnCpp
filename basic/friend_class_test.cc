#include <iostream>

class MyClass {
 public:
  MyClass(int a, int b) : a_(a), b_(b) {}
  // if not set MyFriend can not access a_ and b_
  friend class MyFriend;

 private:
  int a_;
  int b_;
};

class MyFriend {
 public:
  void Print(const MyClass& my_class) {
    std::cout << "a:" << my_class.a_ << std::endl;
    std::cout << "b:" << my_class.b_ << std::endl;
  }
};

int main(int argc, char* argv[]) {
  MyClass my_class(1, 2);
  MyFriend my_friend;
  my_friend.Print(my_class);
  return 0;
}
