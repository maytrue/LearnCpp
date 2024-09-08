#include <iostream>

#include "tbb/parallel_for.h"
#include "tbb/tbb.h"

int main(int argc, char* argv[]) {
  tbb::parallel_for(0, 100, [](int i) { std::cout << i << std::endl; });
  return 0;
}
