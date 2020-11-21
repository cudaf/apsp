#pragma once
#include <vector>
#include "Staging.h"
#include "Table.h"

using std::vector;


namespace cppf {

template <typename V, typename E>
class Graph {
  GraphStaging<V, E> staging;

  void test() {
    staging.push_back({GRAPH_REMOVE_VERTEX, {1}});
  }
};

}
