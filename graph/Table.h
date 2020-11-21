#pragma once
#include <vector>

using std::vector;


// Table graph structures are used when running graph algorithms.
// update() operation generates / updates the table.

namespace cppf {

// Table data for vertices in undirected graph.
template <typename V>
struct GraphVertexEntry {
  int key;
  int any;
  V   value;
};
// key: unique id of vertex
// any: index of in/out edges
// value: vertex data


// Table data for edges in undirected graph.
template <typename E>
struct GraphEdgeEntry {
  int any;
  E   value;
};
// any: index of from/to vertex
// value: edge data



// Table data for vertices in directed graph.
template <typename V>
struct DiGraphVertexEntry {
  int key;
  int in;
  int out;
  V   value;
};
// key: unique id of vertex
// in: index of in edges
// out: index of out edges
// value: vertex data


// Table data for edges in directed graph.
template <typename E>
using DiGraphEdgeEntry = GraphEdgeEntry<E>;



// Table for vertices & edges in undirected graph.
template <typename V, typename E>
struct GraphTable {
  vector<GraphVertexEntry<V>> vertex;
  vector<GraphEdgeEntry<E>>   edge;
};
// vertex: vertex entries
// edge: edge entries


// Table for vertices & edges in directed graph.
template <typename V, typename E>
struct DiGraphTable {
  vector<DiGraphVertexEntry<V>> vertex;
  vector<DiGraphEdgeEntry<E>>   edge;
};
// vertex: vertex entries
// edge: edge entries

}
