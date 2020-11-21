#pragma once
#include <vector>
#include "Staging.h"
#include "Table.h"

using std::vector;


namespace cppf {

template <typename V, typename E>
class Graph {
  
  // Staging area for maintaining temporary data before updating the graph.
  // add() & remove() operations are queued here until and update().
  
  vector<GraphVAdd> vadd;
  vector<GraphEAdd> eadd;
  vector<GraphVRemove> vremove;
  vector<GraphERemove> eremove;
  // vadd: queued addVertex() operations
  // eadd: queued addEdge() operations
  // vremove: queued removeVertex() operations
  // eremove: queued removeEdge() operations



};

}
