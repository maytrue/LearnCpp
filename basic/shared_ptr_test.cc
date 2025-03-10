#include <iostream>
#include <memory>
#include <thread>

class Test {
 public:
  Test() { std::cout << "Test constructor called." << std::endl; }
  ~Test() { std::cout << "Test destructor called." << std::endl; }
  void Print() { std::cout << "Test Print called." << std::endl; }
};

class Engine {
 public:
  Engine() {
    std::cout << "Engine constructor called." << std::endl;
    ptr1_ = std::make_shared<Test>();
  }

  ~Engine() {
    std::cout << "Engine destruct called." << std::endl;
    thread_.detach();
  }

  void Print() {
    thread_ = std::thread([=]() {
      std::cout << "sleep 10s" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(10));

      if (!ptr1_) {
        std::cout << "ptr1_ is nullptr." << std::endl;
        return;
      }
      ptr1_->Print();
      std::cout << "Engine Print called." << std::endl;
    });
  }

 private:
  std::shared_ptr<Test> ptr1_;
  std::thread thread_;
};

int main(int argc, char* argv[]) {
  //   std::shared_ptr<Test> ptr1(new Test());

  //   auto lambda = [ptr1]() {  // 独占捕获
  //     if (!ptr1) {
  //       return;
  //     }
  //     ptr1->Print();
  //   };

  //   ptr1.reset();
  //   if (!ptr1) {
  //     std::cout << "ptr1 is nullptr." << std::endl;
  //   }

  //   lambda();
  auto engine = std::make_shared<Engine>();
  engine->Print();
  engine.reset();

  std::string input;
  std::cin >> input;

  return 0;
}