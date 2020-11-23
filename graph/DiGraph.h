#pragma once
#include <vector>
#include <unordered_map>
#include "Common.h"


// Undirected graph is used when edges of a graph have no direction.
// Both vertices & edges may be weighted.

namespace cppf {
using std::vector;
using std::unordered_map;


template <typename V, typename E>
class DiGraph {
  private:
  unordered_map<int, int>      _lookup;
  vector<GraphVertexEntry<V>>  _vertices;
  vector<GraphEdgeEntry<E>>    _inEdges;
  vector<GraphEdgeEntry<E>>    _outEdges;
  vector<GraphOperation<V, E>> _staging;

  public:
  // staging
  void addVertex(int key, V value);
  void addEdge(int from, int to, E value);
  void removeVertex(int key);
  void removeEdge(int from, int to);
  void clear();
  void update();
  bool isUpdated();

  // properties
  int order();
  int inSize();
  int outSize();
  int size();

  // using unique key
  int inDegree(int key);
  int outDegree(int key);
  int degree(int key);
  vector<GraphVertex<V>> vertices();
  vector<GraphEdge<E>> inEdges();
  vector<GraphEdge<E>> outEdges();
  vector<GraphEdge<E>> edges();
  vector<GraphVertex<V>> inNeighbours(int key);
  vector<GraphVertex<V>> outNeighbours(int key);
  vector<GraphVertex<V>> neighbours(int key);
  vector<GraphEdge<E>> inEdges(int key);
  vector<GraphEdge<E>> outEdges(int key);
  vector<GraphEdge<E>> edges(int key);
  V getVertex(int key);
  E getEdge(int from, int to);
  void setVertex(int key, V value);
  void setEdge(int from, int to, E value);
  int findVertex(int key);
  int findEdge(int from, int to);
  
  // using index (faster)
  GraphVertexEntry<V> v(int i);
  GraphEdgeEntry<E> e(int i);
  V getV(int i);
  E getE(int i);
  void setV(int i, V value);
  void setE(int i, E value);
  int findE(int i, int j);
};


// Number of vertices.
template <typename V, typename E>
inline int DiGraph<V, E>::order() {
  return table.vertex.size();
}


// Number of edges.
template <typename V, typename E>
inline int DiGraph<V, E>::size() {
  return table.edge.size();
}


// All vertices sorted by unique key.
template <typename V, typename E>
inline vector<GraphVertex<V>> DiGraph<V, E>::vertices() {
  auto a;
  for (auto&& v : table.vertex)
    a.push_back({v.key, v.value});
  return a;
}


// _vertices
// _inEdges
// _outEdges
// _staging
template <typename V, typename E>
inline vector<GraphEdge<E>> DiGraph<V, E>::edges() {
  auto a;
  for (auto&& e : table.edge) {

  }
  return a;
}

template <typename V, typename E>
inline pair<int, V> DiGraph<V, E>::vertex(int i) {
  auto v = table.vertex[i];
  return {v.key, v.value};
}


template<typename V, typename E>
inline bool DiGraph<V, E>::isUpdated() {
  return staging.size() == 0;
}

}
