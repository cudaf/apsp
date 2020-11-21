#pragma once
#include <vector>
#include "Staging.h"
#include "Table.h"

using std::vector;


namespace cppf {

template <typename V, typename E>
class Graph {
  GraphTable<V, E>    table;
  GraphStaging<V, E>  staging;
};

}
