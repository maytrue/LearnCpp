#pragma once
#include <memory>

class Car {
 public:
  Car();
  ~Car();
  void Start();

 private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};
