#pragma once
#include <vector>

using std::vector;


// Staging graph structures maintain temporary data before updating a graph.
// add() & remove() operations are queued here until and update().

namespace cppf {

// Temporary data for an addVertex() operation.
template <typename V>
struct GraphAddVertex {
  int key;
  V   value;
};
// key: unique id of vertex
// value: vertex data


// Temporary data for an addEdge() operation.
template <typename E>
struct GraphAddEdge {
  int from;
  int to;
  E   value;
};
// from: source vertex unique id
// to: target vertex unique id
// value: edge data



// Temporary data for a removeVertex() operation.
struct GraphRemoveVertex {
  int key;
};
// key: unique id of vertex


// Temporary data for a removeEdge() operation.
struct GraphRemoveEdge {
  int from;
  int to;
};
// from: source vertex unique id
// to: target vertex unique id



// Indicates the operation type.
enum GraphOperationType {
  GRAPH_ADD_VERTEX,
  GRAPH_ADD_EDGE,
  GRAPH_REMOVE_VERTEX,
  GRAPH_REMOVE_EDGE
};


// Temporary data for add() / remove() operation.
template <typename V, typename E>
struct GraphOperation {
  GraphOperationType  type;
  union {
    GraphAddVertex<V> addVertex;
    GraphAddEdge<E>   addEdge;
    GraphRemoveVertex removeVertex;
    GraphRemoveEdge   removeEdge;
  };
};


// Temporary data for add() / remove() operations.
template <typename V, typename E>
using GraphStaging = vector<GraphOperation<V, E>>;

}
