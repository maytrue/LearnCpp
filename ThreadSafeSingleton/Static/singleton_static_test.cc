#include <glog/logging.h>
#include <glog/raw_logging.h>

#include <iostream>
#include <thread>

#include "util/glog_initializer.h"

class Singleton {
 public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }

  void Print() { LOG(INFO) << "Print"; }

 private:
  Singleton() {
    LOG(INFO) << "Singleton start construct";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    LOG(INFO) << "Singleton end construct";
  }
};

int main(int argc, char* argv[]) {
  cc::GlogInitializer::Init(argv[0]);
  LOG(INFO) << "hello world" << std::endl;

  std::thread t1([] { Singleton::GetInstance().Print(); });

  std::thread t2([] { Singleton::GetInstance().Print(); });

  t1.join();
  t2.join();
  return 0;
}
