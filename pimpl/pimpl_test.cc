#include <iostream>

#include "car.h"

int main(int argc, char const *argv[]) {
  auto car = std::make_shared<Car>();
  car->Start();

  return 0;
}
