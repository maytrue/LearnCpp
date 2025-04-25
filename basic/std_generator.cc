#include <iostream>
#include <vector>
#include <algorithm>

class PacketTimeGenerator {
 public:
  PacketTimeGenerator(int64_t initial_clock, double time_between_packets)
      : initial_clock_(initial_clock),
        time_between_packets_(time_between_packets),
        packets_(0) {}
  int64_t operator()() {
    return initial_clock_ + time_between_packets_ * packets_++;
  }

 private:
  const int64_t initial_clock_;
  const double time_between_packets_;
  size_t packets_;
};

int main(int argc, char* argv[]) {
  std::vector<int64_t> packet_times(10);
  std::generate(packet_times.begin(), packet_times.end(),
                PacketTimeGenerator(0, 33));

  for (const auto& packet_time : packet_times) {
    std::cout << packet_time << " ";
  }
  std::cout << std::endl;
  return 0;
}