323889451
ghia48.serhan@gmail.com
#include <iostream>
#include <cassert>
#include "Graph.hpp"
#include <limits.h>
void testBasicMatrixMultiplication() {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{2, 0}, {1, 2}});

    ariel::Graph result = g1 * g2;
    assert(result.getAdjacencyMatrix()[0][0] == 4);  // 1*2 + 2*1
    assert(result.getAdjacencyMatrix()[0][1] == 4);  // 1*0 + 2*2
    assert(result.getAdjacencyMatrix()[1][0] == 10); // 3*2 + 4*1
    assert(result.getAdjacencyMatrix()[1][1] == 8);  // 3*0 + 4*2


   ariel::Graph g5;

    g5.loadGraph({{0, 1}, {2, 0}});
    ariel::Graph g6 = g5 * 3; // Scalar multiplication

    assert(g6.getAdjacencyMatrix()[0][1] == 3);
    assert(g6.getAdjacencyMatrix()[1][0] == 6);
    assert(g6.getAdjacencyMatrix()[0][0] == 0);
    assert(g6.getAdjacencyMatrix()[1][1] == 0);

    g5 *= 2; // In-place scalar multiplication
    assert(g5.getAdjacencyMatrix()[0][1] == 2);
    assert(g5.getAdjacencyMatrix()[1][0] == 4);
    

    std::cout << "testBasicMatrixMultiplication passed!" << std::endl;
}
void testOverflowHandlingMatrixMultiplication() {
    ariel::Graph g1, g2;
    g1.loadGraph({{INT_MAX, 2}, {3, INT_MIN}});
    g2.loadGraph({{1, 0}, {0, 1}});

    ariel::Graph result = g1 * g2;
    assert(result.getAdjacencyMatrix()[0][0] == INT_MAX); // INT_MAX * 1 + 2 * 0 should still be INT_MAX
    assert(result.getAdjacencyMatrix()[1][1] == INT_MIN); // 3 * 0 + INT_MIN * 1 should still be INT_MIN

    std::cout << "testOverflowHandlingMatrixMultiplication passed!" << std::endl;
}

void testAdvancedOverflowHandlingMatrixMultiplication() {
    ariel::Graph g1, g2;
    g1.loadGraph({{INT_MAX, 1}, {1, INT_MAX}});
    g2.loadGraph({{1, 1}, {1, 1}});

    ariel::Graph result = g1 * g2;
    assert(result.getAdjacencyMatrix()[0][0] == INT_MAX); // Potential overflow, must be capped
    assert(result.getAdjacencyMatrix()[1][1] == INT_MAX); // Potential overflow, must be capped

    std::cout << "testAdvancedOverflowHandlingMatrixMultiplication passed!" << std::endl;
}
void testSizeMismatchException() {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1}});  // Different size

    try {
        ariel::Graph result = g1 * g2;
        assert(false); // Should not reach here, expect to throw before
    } catch (const std::invalid_argument& ex) {
        std::cout << "testSizeMismatchException passed!" << std::endl;
    } catch (...) {
        assert(false); // Incorrect exception type
    }
}


void testGraphMultiplication() {
    ariel::Graph g1, g2;

    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}});

    ariel::Graph result = g1 * g2;

    // Result of matrix multiplication
    assert(result.getAdjacencyMatrix()[0][0] == 19); // 1*5 + 2*7
    assert(result.getAdjacencyMatrix()[0][1] == 22); // 1*6 + 2*8
    assert(result.getAdjacencyMatrix()[1][0] == 43); // 3*5 + 4*7
    assert(result.getAdjacencyMatrix()[1][1] == 50); // 3*6 + 4*8

    // Testing dimension mismatch error
    g2.loadGraph({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    try {
        ariel::Graph result2 = g1 * g2;
        assert(false); // Should not reach here
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Graphs must have the same number of vertices to multiply.");
    }

    std::cout << "Graph multiplication tests passed!" << std::endl;
}

int main() {

    testBasicMatrixMultiplication();
    testOverflowHandlingMatrixMultiplication();
    testAdvancedOverflowHandlingMatrixMultiplication();
    testSizeMismatchException();
    testGraphMultiplication();
    return 0;
}
