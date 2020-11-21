#pragma once
#include <utility>
#include "Table.h"
#include "Staging.h"

using std::pair;
using std::make_pair;


// Undirected graph is used when edges of a graph have no direction.
// Both vertices & edges may be weighted.

namespace cppf {

template <typename V, typename E>
class Graph {
  GraphTable<V, E>    table;
  GraphStaging<V, E>  staging;

  public:
  pair<int, V> vertex(int i);
  bool isUpdated();
};


template <typename V, typename E>
inline pair<int, V> Graph<V, E>::vertex(int i) {
  auto v = table.vertex[i];
  return {v.key, v.value};
}


template<typename V, typename E>
inline bool Graph<V, E>::isUpdated() {
  return staging.size() == 0;
}

}
