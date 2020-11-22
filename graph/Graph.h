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
  int order(); // number of vertices
  int size();  // number of edges
  vector<GraphVertex> vertices();
  vector<GraphEdge> edges();
  vector<GraphVertex> neighbours(int key);
  pair<int, V> vertex(int i);
  V vertexValue(int id);

  bool isUpdated();





  void addVertex(int key, V value) {
    staging.push_back({GRAPH_ADD_VERTEX, {key, value}});
  }

  void addEdge(int from, int to, V value) {
    staging.push_back({GRAPH_ADD_EDGE, {from, to, value}});
  }

  void removeVertex(int key) {
    staging.push_back({GRAPH_REMOVE_VERTEX, {key}});
  }

  void removeEdge(int from, int to) {
    staging.push_back({GRAPH_REMOVE_EDGE, {from, to}});
  }

  void update() {
    for (auto&& op : staging) {
      // some magic
    }
    staging.clear();
  }
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
