#pragma once
#include "Table.h"
#include "Staging.h"


// Undirected graph is used when edges of a graph have no direction.
// Both vertices & edges may be weighted.

namespace cppf {

template <typename V, typename E>
class Graph {
  GraphTable<V, E>    table;
  GraphStaging<V, E>  staging;

  public:
  bool isUpdated();
};

template<typename V, typename E>
inline bool Graph<V, E>::isUpdated() {
  return staging.size() == 0;
}

}
