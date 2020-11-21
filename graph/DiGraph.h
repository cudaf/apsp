#pragma once
#include <vector>
#include "Table.h"

namespace cppf {

template <typename V, typename E>
class DiGraph {

  vector<VEntry> vtable;
  vector<DiGraphEEntry<E>> etable;
  vector<int32_t> vlookup;

  // staging area
  vector<int32_t> vremove;
  vector<int64_t> eremove;
  vector<int32_t> vadd;
  vector<int64_t> eadd;

public:
  // bool hasVertex();
  // bool hasEdge();
  // vector<int> vertices();
  // vector<int64_t> edges(i, in/out);
  // vertex(i);
  // edge(i);
  // degree(i, in/out);
  // dijkstra(i, in/out)
  // int order(); // number of vertices
  // int size(); // number of edges
  // bool isComplete();
  // bool isConnected();
  // bool isBipartite();
  // bool isPlanar();
  // bool isTriangleFree();
  // bool isPerfect();
  // bool isEulerian();
  // bool isHamiltonian();
  // int connectedComponents();
  // int circuitRank();
  // int diameter();
  // int girth();
  // int vertexConnectivity();
  // int edgeConnectivity();
  // int chromaticNumber();
  // int chromaticIndex();
  // int choosability();
  // int independenceNumber();
  // int cliqueNumber();
  // int arboricity();
  // int graphGenus();
  // int pageNumber();
  // int hosoyaIndex();
  // int wienerIndex();
  // int colinDeVerdiereGraphInvariant();
  // int boxicity();
  // float clusteringCoefficient();
  // float betweenessCentrality();
  // float fractionalChromaticNumber();
  // float algebraicConnectivity();
  // float isoperimetricNumber();
  // float estradaIndex();
  // float strength();
};

}
