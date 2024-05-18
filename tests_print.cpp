323889451
ghia48.serhan@gmail.com

#include <iostream>
#include <cassert>
#include <sstream>
#include "Graph.hpp"

void testOutputOperator() {
    ariel::Graph g1;

    g1.loadGraph({{0, 1, 2}, {3, 0, 4}, {5, 6, 0}});
    std::ostringstream output;
    output << g1;
   std::cout << output.str() << std::endl;
    std::string expectedOutput =
        "Graph with 3 vertices and 6 edges.\n"
        "Adjacency Matrix:\n"
        "0 1 2 \n"
        "3 0 4 \n"
        "5 6 0 \n";

    assert(output.str() == expectedOutput);
    std::cout << "Output operator test passed!" << std::endl;
}

int main() {
    testOutputOperator();
    return 0;
}
