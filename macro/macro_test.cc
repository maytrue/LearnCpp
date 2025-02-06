#include <iostream>

// Notes about macro
// 1. # stringify
// 2. ## concat two variable together
// 3. ##__VA_ARGS__

#define STRINGIFY(x) #x
#define CONCAT(a, b) a##b

#define PRINT1(format, ...) fprintf(stdout, format, ##__VA_ARGS__)
#define PRINT2(format, args...) fprintf(stdout, format, args)

int main(int argc, char const *argv[]) {
  /* code */
  int CONCAT(my, Variable) = 42;
  std::cout << "myVariable:" << myVariable << std::endl;

  std::string greet = STRINGIFY(hello wolrd);
  std::cout << greet << std::endl;

  PRINT1("abc\n");
  PRINT1("%d, %s\n", 32, "hello");
  PRINT2("%d, %s\n", 33, "world");

  return 0;
}
