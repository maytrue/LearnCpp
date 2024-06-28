#include "car.h"

#include <iostream>

class Car::Impl {
 public:
  Impl() { std::cout << "Impl()" << std::endl; }
  ~Impl() { std::cout << "~Impl()" << std::endl; }
  void Start() { std::cout << "Car::Start()" << std::endl; }
};

Car::Car() : impl_(std::make_unique<Impl>()) {}

Car::~Car() { std::cout << "Car::~Car()" << std::endl; }

void Car::Start() { impl_->Start(); }
