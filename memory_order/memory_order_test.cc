//
// Created by zouguowei on 2025/7/16.
//

#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> data(0);
std::atomic<bool> ready(false);

void Producer() {
  data.store(43, std::memory_order_relaxed);
  ready.store(true, std::memory_order_release);
}

void Consumer() {
  while (!ready.load(std::memory_order_acquire)) {}
  std::cout << "Consumer consumed: " << data.load(std::memory_order_relaxed) << std::endl;
}

int main(int argc, char* argv[]) {
  std::thread t1(Producer);
  std::thread t2(Consumer);

  t1.join();
  t2.join();


  return 0;
}