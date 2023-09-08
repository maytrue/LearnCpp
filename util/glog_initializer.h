#include <glog/logging.h>
#include <glog/raw_logging.h>

#include <iomanip>
#include <iostream>

namespace cc {

using namespace std;
using namespace google;

void CustomPrefix(std::ostream &s, const LogMessageInfo &l, void *) {
  //  s << l.severity[0]
  s << "[" << setw(4) << 1900 + l.time.year() << setw(2) << 1 + l.time.month()
    << setw(2) << l.time.day() << ' ' << setw(2) << l.time.hour() << ':'
    << setw(2) << l.time.min() << ':' << setw(2) << l.time.sec() << "."
    << setw(6) << l.time.usec() << "]" << ' ' << setfill(' ')
    << "[tid:" << setw(5) << l.thread_id << setfill('0') << "]" << ' ' << "["
    << l.severity[0] << "]"
    << " [" << l.filename << ':' << l.line_number << "]";
}

class GlogInitializer {
 public:
  static void Init(const char* argv0) {
    google::InitGoogleLogging(argv0, &CustomPrefix);
    google::LogToStderr();
  }

 private:
  GlogInitializer() {
  }
};

}  // namespace cc
