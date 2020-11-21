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



// Temporary data for add() operations.

template <typename V, typename E>
struct GraphAdd {
  vector<GraphAddVertex<V>> vertex;
  vector<GraphAddEdge<E>>   edge;
};
// vertex: for addVertex() operation
// edge: for addEdge() operation


// Temporary data for remove() operations.

struct GraphRemove {
  vector<GraphRemoveVertex> vertex;
  vector<GraphRemoveEdge>   edge;
};
// vertex: for removeVertex() operation
// edge: for removeEdge() operation



// Temporary data for add()/remove() operations.

template <typename V, typename E>
struct GraphStaging {
  GraphAdd<V, E>  add;
  GraphRemove     remove;
};
// add: for add() operations
// remove: for remove() operations

}
