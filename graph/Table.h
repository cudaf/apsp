#pragma once


namespace cppf {

// Table data for vertices in undirected graph.
template <typename V>
struct GraphVEntry {
  int key;
  int any;
  V   value;
};
// key: unique id of vertex
// any: index of in/out edges
// value: vertex data


// Table data for edges in undirected graph.
template <typename E>
struct GraphEEntry {
  int any;
  E   value;
};
// any: index of from/to vertex
// value: edge data



// Table data for vertices in directed graph.
template <typename V>
struct DiGraphVEntry {
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
using DiGraphEEntry = GraphEEntry<E>;

}
