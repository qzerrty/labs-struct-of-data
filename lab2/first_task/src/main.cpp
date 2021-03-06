#include <iostream>
#include <fstream>
#include "MatrixGraph/MatrixGraph.hpp"
#include "ListGraph/ListGraph.hpp"

int main() {
  std::fstream input;
  input.open("../src/inputFiles/input1.txt");
  // input.open("../src/inputFiles/input2.txt");
  // input.open("../src/inputFiles/input3.txt");
  // input.open("../src/inputFiles/input4.txt");

  unsigned int sizeOfGraph = 0;
  input >> sizeOfGraph;

  MatrixGraph m_graph(sizeOfGraph);
  ListGraph l_graph(sizeOfGraph);

  int tmp = 0;
  for (unsigned char i = 0; i < sizeOfGraph; i++) {
    for (unsigned char j = 0; j < sizeOfGraph; j++) {
      input >> tmp;
      if (tmp != 0) {
        m_graph.addEdge(i, j);
        l_graph.addEdge(i, j);
      }
    }
  }

  std::cout << "###### Result from Matrix Graph ######" << std::endl;
  std::cout << "index of stoks: " << m_graph.findAllStocks() << std::endl;
  std::cout << "index of rises: " << m_graph.findAllRises() << std::endl;
  std::cout << "count of trees: " << m_graph.minCountOfTrees() << std::endl;
  std::cout << "######################################" << std::endl;

  std::cout << "######  Result from List Graph  ######" << std::endl;
  std::cout << "index of stoks: " << l_graph.findAllStocks() << std::endl;
  std::cout << "index of rises: " << l_graph.findAllRises() << std::endl;
  std::cout << "count of trees: " << l_graph.minCountOfTrees() << std::endl;
  std::cout << "######################################" << std::endl;

  input.close();
}
