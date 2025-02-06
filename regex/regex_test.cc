#include <iostream>
#include <regex>

int main(int argc, char* argv[]) {
  std::regex re(R"(test_(\d{4})_(\d{2})_(\d{2})_(\d{2})_(\d{2})_(\d{2})\.log)");
  std::string s("test_2025_01_15_16_47_56.log");

  std::smatch match;
  if (std::regex_match(s, match, re)) {
    std::cout << "Matched" << std::endl;
    std::cout << "Matched string: " << match.str() << std::endl;
    std::cout << "Matched size: " << match.size() << std::endl;
    for (size_t i = 0; i < match.size(); ++i) {
      std::cout << "Matched group " << i << ": " << match[i] << std::endl;
    }
  } else {
    std::cout << "Not matched" << std::endl;
  }

  return 0;
}