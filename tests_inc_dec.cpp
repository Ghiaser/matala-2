323889451
ghia48.serhan@gmail.com
#include <iostream>
#include <cassert>
#include "Graph.hpp"
#include <limits.h>
void testIncrement() {
    ariel::Graph g1;

    g1.loadGraph({{0, 1}, {2, 0}});
    ariel::Graph preInc = ++g1; // Testing prefix increment
    assert(preInc.getAdjacencyMatrix()[0][1] == 2 && preInc.getAdjacencyMatrix()[1][0] == 3);
    std::cout << "Prefix increment test passed!" << std::endl;

    g1.loadGraph({{0, 1}, {2, 0}});
    ariel::Graph postInc = g1++; // Testing postfix increment
    assert(g1.getAdjacencyMatrix()[0][1] == 2 && g1.getAdjacencyMatrix()[1][0] == 3); // g1 should be incremented
    assert(postInc.getAdjacencyMatrix()[0][1] == 1 && postInc.getAdjacencyMatrix()[1][0] == 2); // postInc should hold old values
    std::cout << "Postfix increment test passed!" << std::endl;
}

void testDecrement() {
    ariel::Graph g1;

    g1.loadGraph({{0, 3}, {4, 0}});
    ariel::Graph preDec = --g1; // Testing prefix decrement
    assert(preDec.getAdjacencyMatrix()[0][1] == 2 && preDec.getAdjacencyMatrix()[1][0] == 3);
    std::cout << "Prefix decrement test passed!" << std::endl;

    g1.loadGraph({{0, 3}, {4, 0}});
    ariel::Graph postDec = g1--; // Testing postfix decrement
    assert(g1.getAdjacencyMatrix()[0][1] == 2 && g1.getAdjacencyMatrix()[1][0] == 3); // g1 should be decremented
    assert(postDec.getAdjacencyMatrix()[0][1] == 3 && postDec.getAdjacencyMatrix()[1][0] == 4); // postDec should hold old values
    std::cout << "Postfix decrement test passed!" << std::endl;
}
void testIncrementDecrementLimits() {
    ariel::Graph g;

    g.loadGraph({{INT_MAX, INT_MIN}, {0, -1}});

    // Test Increment
    ++g;
    assert(g.getAdjacencyMatrix()[0][0] == INT_MAX);  // Check INT_MAX is unchanged
    assert(g.getAdjacencyMatrix()[0][1] == INT_MIN + 1);  // Check INT_MIN is incremented
    assert(g.getAdjacencyMatrix()[1][1] == 0);       // no edge no change
    std::cout << g.getAdjacencyMatrix()[1][1] << std::endl;

    // Test Decrement
    --g;
    assert(g.getAdjacencyMatrix()[0][0] == INT_MAX - 1);  // Check INT_MAX is decremented
    assert(g.getAdjacencyMatrix()[0][1] == INT_MIN);  // Check INT_MIN is unchanged after being incremented then decremented
    std::cout << g.getAdjacencyMatrix()[1][1] << std::endl;
    assert(g.getAdjacencyMatrix()[1][1] == 0);       // no edge no change

    std::cout << "testIncrementDecrementLimits passed!" << std::endl;
}




int main() {
    testIncrement();
    testDecrement();
    testIncrementDecrementLimits();
    return 0;
}
