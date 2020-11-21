#pragma once

// Staging graph structures maintain temporary data before updating a graph.
// add() & remove() operations are queued here until and update().
namespace cppf {

// Temporary data for an addVertex() operation.
template <typename V>
struct GraphVAdd {
  int id;
  V   data;
};
// id: unique id of vertex
// data: associated data


// Temporary data for an addEdge() operation.
template <typename E>
struct GraphEAdd {
  int from;
  int to;
  E   data;
};
// from: source vertex unique id
// to: target vertex unique id
// data: associated data


// Temporary data for a removeVertex() operation.
struct GraphVRemove {
  int id;
};
// id: unique id of vertex


// Temporary data for a removeEdge() operation.
struct GraphERemove {
  int from;
  int to;
};
// from: source vertex unique id
// to: target vertex unique id

}
