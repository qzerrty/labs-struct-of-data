#pragma once
#include "Array/Array.hpp"

class MatrixGraph {
private:
  int* matrix;
  unsigned char length;

public:
  MatrixGraph(unsigned char);
  ~MatrixGraph();
  void addEdge(int, int);
  void removeEdge(int, int);
  Array* findAllStocks();
  Array* findAllRises();

};