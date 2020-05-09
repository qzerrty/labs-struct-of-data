#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(unsigned char length) {
  matrix = new int[length * length];
  this->length = length;
}

MatrixGraph::~MatrixGraph() {
  delete[] matrix;
}

void MatrixGraph::addEdge(int i, int j) {
  matrix[i * length + j] = 1;
}

void MatrixGraph::removeEdge(int i, int j) {
  matrix[i * length + j] = 0;
}

Array* MatrixGraph::findAllStocks() {
  Array* stocks = new Array(0);

  bool isStock;
  for (unsigned char i = 0; i < length; i++) {
    isStock = true;
    for (unsigned char j = 0; j < length; j++) {
      if (matrix[i * length + j] != 0) {
        isStock = false;
        break;
      }
    }
    if (isStock) stocks->push((int) i + 1);
  }

  return stocks;
}

Array* MatrixGraph::findAllRises() {
  Array* rises = new Array(0);

  bool isRise;
  for (unsigned char i = 0; i < length; i++) {
    isRise = true;
    for (unsigned char j = 0; j < length; j++) {
      if (matrix[j * length + i] != 0) {
        isRise = false;
        break;
      }
    }
    if (isRise) rises->push((int) i + 1);
  }
  
  return rises;
}
