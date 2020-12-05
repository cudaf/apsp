#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Common.h"


// Undirected graph is used when edges of a graph have no direction.
// Both vertices & edges may be weighted.

namespace cppf {
using std::vector;
using std::unordered_map;
using std::binary_search;


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
  void addVertices(vector<GraphVertex<V>> vs);
  void addEdges(vector<GraphEdge<E>> es);
  void removeVertices(vector<GraphVertexKey<V>> vs);
  void removeEdges(vector<GraphEdgeKey<E>> es);
  void clear();
  // update()
  // isUpdated()

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
  
  inline V getVertex(int key) {
    return getV(findV(key));
  }

  inline E getInEdge(int from, int to) {
    return getInE(findV(from), findV(to));
  }

  inline void setVertex(int key, V value) {
    setV(findV(key), value);
  }

  inline void setInEdge(int from, int to, E value) {
    setInE(findV(from), findV(to), value);
  }

  inline void setOutEdge(int from, int to, E value) {
    setOutE(findV(from), findV(to), value);
  }

  inline int findVertex(int key) {
    return findV(key);
  }

  inline int findInEdge(int from, int to) {
    return findInE(findV(from), findV(to));
  }

  inline int findOutEdge(int from, int to) {
    return findOutE(findV(from), findV(to));
  }
  
  
  // using index (faster)
  inline GraphVertexEntry<V> v(int i) {
    return _vertices[i];
  }

  inline GraphEdgeEntry<E> inE(int i) {
    return _inEdges[i];
  }

  inline GraphEdgeEntry<E> outE(int i) {
    return _outEdges[i];
  }

  inline V getV(int i) {
    return v(i).value;
  }

  inline E getInE(int i) {
    return inE(i).value;
  }

  inline E getOutE(int i) {
    return outE(i).value;
  }

  inline void setV(int i, V value) {
    _vertices[i].value = value;
  }

  inline void setInE(int i, E value) {
    _inEdges[i].value = value;
  }

  inline void setOutE(int i, E value) {
    _outEdges[i].value = value;
  }

  inline int findV(int key) {
    return binary_search(_vertices.begin(), _vertices.end(), {0, 0, key});
  }

  inline int findInE(int i, int j) {
    return binary_search(_inEdges.begin(), _inEdges.end(), {i, j});
  }

  inline int findOutE(int i, int j) {
    return binary_search(_outEdges.begin(), _outEdges.end(), {i, j});
  }
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
