#include <functional>
#include <iostream>
#include <memory>

class AInterface {
 public:
  virtual ~AInterface() = default;
  virtual void OnFinish() = 0;
};

class A {
 public:
  A() { std::cout << "A()" << std::endl; }

  ~A() { std::cout << "~A()" << std::endl; }

  void SetListener(std::shared_ptr<AInterface> ptr) { ptr_ = ptr; }

  void SetListener(std::shared_ptr<std::function<void()>> ptr) {
    ptr_func_ = ptr;
  }

  void Print() {
    std::cout << "Print" << std::endl;
    auto ptr = ptr_func_.lock();
    if (ptr) {
      (*ptr)();
    } else {
      std::cout << "ptr_func_ is expired" << std::endl;
    }
  }

 private:
  std::weak_ptr<AInterface> ptr_;
  std::weak_ptr<std::function<void()>> ptr_func_;
};

class B {
 public:
  B() { std::cout << "B()" << std::endl; }

  ~B() { std::cout << "~B()" << std::endl; }

  void SetA(std::shared_ptr<A> a) {
    a_ = a;
    // a_interface_ = std::make_shared<AInterface>();
    ptr_func_ = std::make_shared<std::function<void()>>(
        [this]() { std::cout << "OnFinish" << std::endl; });

    a_->SetListener(ptr_func_);
  }

  void Print() {}

  std::shared_ptr<AInterface> GetInterface() { return a_interface_; }

  class Test : public AInterface {
   public:
    void OnFinish() override { std::cout << "OnFinish" << std::endl; }
  };

 private:
  std::shared_ptr<A> a_;
  std::string result_;
  std::shared_ptr<AInterface> a_interface_;
  std::shared_ptr<std::function<void()>> ptr_func_;
};

int main(int argc, char* argv[]) {
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();
  b->SetA(a);
  b.reset();

  a->Print();

  std::cin >> argc;

  // b->Print();

  // a->SetListener(b->GetInterface());
  // a->Print();

  return 0;
}