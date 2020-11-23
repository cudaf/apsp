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



// A vertex without value.
struct GraphVertexKey {
  int key;
};
// key: unique key


// An edge without value.
struct GraphEdgeKey {
  int from;
  int to;
};
// from: source vertex key
// to: target vertex key



// Table data for vertices in graph.
template <typename V>
struct GraphVertexEntry {
  int in;
  int out;
  int key;
  V   value;
};
// in: index of in edges
// out: index of out edges
// key: unique key
// value: associated value


// Table data for edges in graph.
template <typename E>
struct GraphEdgeEntry {
  int any;
  E   value;
};
// any: index of from/to vertex
// value: associated value



// Indicates staging operation type.
enum GraphOperationType {
  GRAPH_CLEAR,
  GRAPH_ADD_VERTEX,
  GRAPH_ADD_EDGE,
  GRAPH_REMOVE_VERTEX,
  GRAPH_REMOVE_EDGE
};


// Temporary data for add() / remove() staging operation.
template <typename V, typename E>
struct GraphOperation {
  GraphOperationType      type;
  union {
    GraphVertex<V> addVertex;
    GraphEdge<E>   addEdge;
    GraphVertexKey removeVertex;
    GraphEdgeKey   removeEdge;
  };
};

}
