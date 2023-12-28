#include <iostream>
#include <thread>

#include "util/spdlog_initializer.h"

class Singleton {
 public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }

  void Print() { LOG_INFO("Print"); }

 private:
  Singleton() {
    LOG_INFO("Singleton start construct");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    LOG_INFO("Singleton end construct");
  }
};

int main(int argc, char* argv[]) {
  rtcserver::SpdlogInitializer::Init();
  LOG_INFO("helo world");

  std::thread t1([] { Singleton::GetInstance().Print(); });

  std::thread t2([] { Singleton::GetInstance().Print(); });

  t1.join();
  t2.join();
  return 0;
}
