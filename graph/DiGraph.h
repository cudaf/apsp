#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Common.h"


// Undirected graph is used when edges of a graph have no direction.
// Both vertices & edges may be weighted.

namespace cppf {
using std::pair;
using std::tuple;
using std::vector;
using std::unordered_map;
using std::fill;
using std::transform;
using std::binary_search;


// TODO: addEdge affects all vertex pointers
// TODO: implement reverse
template <typename V, typename E>
class DiGraph {
  private:
  vector<GraphVertexEntry<V>> _vertices;
  vector<GraphEdgeEntry<E>>   _edges;

  public:
  void addVertex(int key, V value);
  void addVertices(vector<GraphVertex<V>> vertices);
  void removeVertex(int key);
  void removeVertices(vector<int> keys);
  void addEdge(int from, int to, E value);
  void addEdges(vector<GraphEdge<E>> edges); 
  void removeEdge(int from, int to);
  void removeEdges(const vector<pair<int, int>>& edges);
  void compress(bool vertices);
  void clear();
  // Graph update

  DiGraph<V, E> subgraph(int begin, int end);
  DiGraph<V, E> subgraph(vector<int> vertices);
  DiGraph<V, E> reverse();
  // Graph generate

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
  bool validVertex(int key);
  bool hasVertex(int key);
  // Vertex properties

  E getEdge(int key);
  void setEdge(int key, E value);
  int toVertex(int key);
  int fromVertex(int key);
  bool validEdge(int key);
  bool hasEdge(int from, int to);
  // Edge properties

  private:
  void compressEdges();
  void compressVertices();
  void shrinkVertices(int n);
  void remapEdges(const vector<int>& keys);
  void invalidateVertex(int key);
  void invalidateEdge(int key);
  void outEdge(int key, int out);
  void toVertex(int key, int to);
};


// Add vertex to graph.
template <typename V, typename E>
inline void DiGraph<V, E>::addVertex(int key, V value) {
  int n = order();
  if (key >= n) {
    _vertices.resize(key+2);
    fill(_vertices.begin()+n, _vertices.end(), outEdge(n));
  }
  setVertex(key, value);
}
/// expand(key+1)


// Add vertices to graph (sorted!).
template <typename V, typename E>
inline void DiGraph<V, E>::addVertices(vector<GraphVertex<V>> vertices) {
  if (vertices.size() == 0) return;
  auto&& v = vertices.back();
  addVertex(v.key, v.value);
  for (auto&& v : vertices)
    setVertex(v.key, v.value);
}




// markRemoveVertex
// emptyVertex


// Add edge to graph.
template <typename V, typename E>
inline void DiGraph<V, E>::addEdge(int from, int to, E value) {
  _edges.insert(outEdge(from+1), {to, value});
  for (int i=from+1, I=order()+1; i<I; i++)
    _vertices[i].out++;
}


template <typename V, typename E>
inline void DiGraph<V, E>::addEdges(vector<GraphEdge<E>> edges) {
  int E = size();
  int n = edges.size();
  _edges.resize(E+n);
  for (int e=E-1, f=e+n; e>=0; e--) {
    
  }
}


// Mark vertex for removal.
template <typename V, typename E>
inline void DiGraph<V, E>::removeVertex(int key) {
  for (int e=outEdge(key), E=outEdge(key+1); e<E; e++)
    invalidateEdge(e);
  for (int e=0, E=size(); e<E; e++)
    if (toVertex(e) == key) invalidateEdge(e);
  invalidateVertex(key);
}


// Mark edge for removal.
template <typename V, typename E>
inline void DiGraph<V, E>::removeEdge(int from, int to) {
  for (int e=outEdge(from), E=outEdge(from+1); e<E; e++)
    if (toVertex(e) == to) invalidateEdge(e);
}


// Clear vertices/edges marked for removal.
template <typename V, typename E>
inline void DiGraph<V, E>::compress(bool vertices=false) {
  if (vertices) compressVertices();
  compressEdges();
}


// Removes all vertices and edges.
template <typename V, typename E>
void DiGraph<V, E>::clear() {
  _vertices.clear();
  _edges.clear();
  _vertices.push_back({0});
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
  return outEdge(key+1) - outEdge(key);
}


// Number of inward edges to a vertex.
template <typename V, typename E>
inline int DiGraph<V, E>::inDegree(int key) {
  int a = 0;
  for (int i=0, I=size(); i<I; i++)
    if (toVertex(i) == key) a++;
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
  for (int i=0, I=size(); i<I; i++)
    if (toVertex(i) == key) a.push(i);
  return a;
}


// Is vertex marked as removed?
template <typename V, typename E>
inline bool DiGraph<V, E>::validVertex(int key) {
  return outEdge(key) >= 0;
}


// Is vertex part of graph?
template <typename V, typename E>
inline bool DiGraph<V, E>::hasVertex(int key) {
  return key < order() && validVertex(key);
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
  for (int i=0, I=order()+1; i<I; i++)
    if (outEdge(i) > key) return i-1;
  return -1;
}


// Is edge marked as removed?
template <typename V, typename E>
inline bool DiGraph<V, E>::validEdge(int key) {
  return toVertex(key) >= 0;
}


// Is edge part of graph?
template <typename V, typename E>
inline bool DiGraph<V, E>::hasEdge(int from, int to) {
  if (!hasVertex(from) || !hasVertex(to)) return false;
  for (int i=outEdge(from), I=outEdge(key+1); i<I; i++)
    if (toVertex(i) == to) return true;
  return false;
}


// Clear vertices marked for removal!
template <typename V, typename E>
void DiGraph<V, E>::compressVertices() {
  vector<int> keys(order());
  for (int v=0, w=0, V=order(); v<V; v++) {
    _vertices[w] = _vertices[v]; keys[v] = w;
    if (validVertex(v)) w++;
  }
  shrinkVertices(w);
  remapEdges(keys);
}


// Clear edges marked for removal!
template <typename V, typename E>
void DiGraph<V, E>::compressEdges() {
  for (int v=0, e=0, f=0, E=size(); e<E; e++) {
    while (e >= outEdge(v+1)) v++;
    _edges[f] = _edges[e];
    if (validEdge(e)) f++;
    else _vertices[v+1].out--;
  }
  _edges.resize(f);
}


// Reduce vertices of graph!
template <typename V, typename E>
void DiGraph<V, E>::shrinkVertices(int n) {
  _vertices[n].out = size();
  _vertices.resize(n+1);
}


// Remaps all edges with new keys.
template <typename V, typename E>
void DiGraph<V, E>::remapEdges(const vector<int>& keys) {
  for (auto& e : _edges)
    if (e.to >= 0) e.to = keys[e.to];
}

}
