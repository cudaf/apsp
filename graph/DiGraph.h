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
  vector<GraphVertexEntry<V>> _vertices;
  vector<GraphEdgeEntry<E>>   _edges;

  public:
  // update
  void addVertex(int key, V value);
  void addVertices(vector<GraphVertex<V>> vs);
  void removeVertex(int key);
  void removeVertices(vector<GraphVertexKey<V>> vs);
  void addEdge(int from, int to, E value);
  void addEdges(vector<GraphEdge<E>> es);
  void removeEdge(int from, int to);
  void removeEdges(vector<GraphEdgeKey<E>> es);
  void flush();
  void clear();

  // graph properties
  int order();
  int size();

  // vertex properties
  V getVertex(int key);
  void setVertex(int key, V value);
  int outDegree(int key);
  int inDegree(int key);
  int outEdge(int key);
  vector<int> outEdges(int key);
  vector<int> inEdges(int key);

  // edge properties
  E getEdge(int key);
  void setEdge(int key, E value);
  int toVertex(int key);
  int fromVertex(int key);
};

}
