// #include <tbb/flow_graph.h>
#include <iostream>

#include "tbb/flow_graph.h"
#include "tbb/parallel_for.h"
#include "tbb/tbb.h"
#include "util/spdlog_initializer.h"

int main(int argc, char* argv[]) {
  rtcserver::SpdlogInitializer::Init();
  LOG_INFO("start tbb flow graph, current:{}",
           tbb::info::default_concurrency());
  tbb::flow::graph g;

  // define a function node that squares its input
  tbb::flow::function_node<int, int> square(g, tbb::flow::unlimited,
                                            [](int i) -> int {
                                              LOG_INFO("do job:{}", i);
                                              return i * i;
                                            });

  // define a function node that prints its input
  tbb::flow::function_node<int> print(g, tbb::flow::unlimited,
                                      [](int i) { LOG_INFO("{}", i); });

  // make square node the predecessor of print node
  tbb::flow::make_edge(square, print);

  for (int i = 0; i < 10; ++i) {
    // send values to the square node
    square.try_put(i);
  }
  // send values to the square node
  // square.try_put(2);

  g.wait_for_all();

  return 0;
}
