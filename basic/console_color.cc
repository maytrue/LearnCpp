#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

#include <iostream>

int main() {
  std::cout << RED << "Error: Something went wrong!" << RESET << "\n";
  std::cout << GREEN << "Success: Operation completed!" << RESET << "\n";
  std::cout << BOLD << BLUE << "Notice: Check your settings." << RESET << "\n";
  return 0;
}