#pragma once
#include <limits.h>
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
  vector<GraphVertexEntry<V>> _vertices;
  vector<GraphEdgeEntry<E>>   _edges;

  public:
  void addVertex(int key, V value);
  void removeVertex(int key);
  void addEdge(int from, int to, E value);
  void removeEdge(int from, int to);
  void clear();
  // Graph update

  int order();
  int size();
  // Graph properties

  V getVertex(int key);
  void setVertex(int key, V value);
  int outDegree(int key);
  int inDegree(int key);
  int outEdge(int key);
  vector<int> outEdges(int key);
  vector<int> inEdges(int key);
  // Vertex properties

  E getEdge(int key);
  void setEdge(int key, E value);
  int toVertex(int key);
  int fromVertex(int key);
  // Edge properties
};


// Add vertex to graph.
template <typename V, typename E>
inline void DiGraph<V, E>::addVertex(int key, V value) {
  if (key >= order()) _vertices.resize(key+1);
  setVertex(key, value);
}


// Remove vertex from graph.
template <typename V, typename E>
inline void DiGraph<V, E>::removeVertex(int key) {
  for (auto&& e : outEdges(key))
    e.to = -1;
  for (auto&& e : inEdges(key))
    e.to = -1;
  _vertices[key].out = -1;
}


// Add edge to graph.
template <typename V, typename E>
inline void DiGraph<V, E>::addEdge(int from, int to, E value) {
  _edges.insert(outEdge(from+1), {to, value});
}


// Remove edge from graph.
template <typename V, typename E>
inline void DiGraph<V, E>::removeEdge(int from, int to) {
  for (int i=outEdge(from), I=outEdge(from+1); i<I; i++)
    if (_edges[i].to == to) _edges[i].to = -1;
}


// Removes all vertices and edges.
template <typename V, typename E>
inline void DiGraph<V, E>::clear() {
  _vertices.clear();
  _edges.clear();
  _vertices.push_back({INT_MAX});
}


// Number of vertices.
template <typename V, typename E>
inline int DiGraph<V, E>::order() {
  return _vertices.size() - 1;
}


// Number of edges.
template <typename V, typename E>
inline int DiGraph<V, E>::size() {
  return _edges.size();
}


// Get vertex value.
template <typename V, typename E>
inline V DiGraph<V, E>::getVertex(int key) {
  return _vertices[key].value;
}


// Set vertex value.
template <typename V, typename E>
inline void DiGraph<V, E>::setVertex(int key, V value) {
  _vertices[key].value = value;
}


// Number of outward edges from a vertex.
template <typename V, typename E>
inline int DiGraph<V, E>::outDegree(int key) {
  return _vertices[key+1].out - _vertices[key].out;
}


// Number of inward edges to a vertex.
template <typename V, typename E>
inline int DiGraph<V, E>::inDegree(int key) {
  int a = 0;
  for (auto&& e : _edges)
    if (e.to == key) a++;
  return a;
}


// First outward edge from vertex.
template <typename V, typename E>
inline int DiGraph<V, E>::outEdge(int key) {
  return _vertices[key].out;
}


// Outward edges from vertex.
template <typename V, typename E>
inline vector<int> DiGraph<V, E>::outEdges(int key) {
  vector<int> a;
  for (int i=outEdge(key), I=outEdge(key+1); i<I; i++)
    a.push_back(i);
  return a;
}


// Inward edges to vertex.
template <typename V, typename E>
inline vector<int> DiGraph<V, E>::inEdges(int key) {
  vector<int> a;
  for (int i=0, I=_edges.size(); i<I; i++)
    if (_edges[i].to == key) a.push(i);
  return a;
}


// Get edge value.
template <typename V, typename E>
inline E DiGraph<V, E>::getEdge(int key) {
  return _edges[key].value;
}


// Set edge value.
template <typename V, typename E>
inline void DiGraph<V, E>::setEdge(int key, E value) {
  _edges[key].value = value;
}


// Vertex this edge goes to.
template <typename V, typename E>
inline int DiGraph<V, E>::toVertex(int key) {
  return _edges[key].to;
}


// Vertex this edge comes from.
template <typename V, typename E>
inline int DiGraph<V, E>::fromVertex(int key) {
  for (int i=0, I=_vertices.size(); i<I; i++)
    if (_vertices[i].out > key) return i-1;
  return -1;
}

}
