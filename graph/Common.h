#pragma once


// Common graph structures.

namespace cppf {


// A vertex has a unique key & a value.
template <typename V>
struct GraphVertex {
  int key;
  V   value;
};
// key: unique key
// value: associated value


// An edge has 2 vertices & a value.
template <typename E>
struct GraphEdge {
  int from;
  int to;
  E   value;
};
// from: source vertex key
// to: target vertex key
// value: associated value



// Table data for vertices in graph.
template <typename V>
struct GraphVertexEntry {
  int out;
  V   value;
};
// out: index of out edges
// value: associated value


// Table data for edges in graph.
template <typename E>
struct GraphEdgeEntry {
  int to;
  E   value;
};
// to: index of to vertex
// value: associated value

}
