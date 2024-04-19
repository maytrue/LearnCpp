#include <iostream>
#include <map>
#include <thread>

static bool running = true;

std::string FindVersionName(int version) {
  static std::map<int, std::string> map = {
      {1, "1"},
      {2, "2"},
      {3, "3"},
  };

  auto it = map.find(version);
  if (it != map.end()) {
    return it->second;
  }
  return "";
}

void Test() {
  while (running) {
    FindVersionName(2);
  }
}

int main(int argc, char const *argv[]) {
  std::thread thread[100];

  for (int i = 0; i < 100; i++) {
    thread[i] = std::thread(Test);
    thread[i].detach();
  }

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "exit" << std::endl;
  running = false;
  return 0;
}
