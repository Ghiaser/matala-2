323889451
ghia48.serhan@gmail.com
#include "Graph.hpp"
#include <cassert>
#include <iostream>
#include <limits.h>
void testGraphAddition() {
    ariel::Graph g1, g2;

    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}});

    ariel::Graph sum = g1 + g2;
    const auto& sumMatrix = sum.getAdjacencyMatrix();

    assert(sumMatrix[0][0] == 6);
    assert(sumMatrix[0][1] == 8);
    assert(sumMatrix[1][0] == 10);
    assert(sumMatrix[1][1] == 12);

    std::cout << "testGraphAddition passed!" << std::endl;
}

void testGraphAdditionAssignment() {
    ariel::Graph g1, g2;

    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{5, 6}, {7, 8}});

    g1 += g2;
    const auto& resultMatrix = g1.getAdjacencyMatrix();

    assert(resultMatrix[0][0] == 6);
    assert(resultMatrix[0][1] == 8);
    assert(resultMatrix[1][0] == 10);
    assert(resultMatrix[1][1] == 12);

    std::cout << "testGraphAdditionAssignment passed!" << std::endl;
}

void testGraphSubtraction() {
    ariel::Graph g1, g2;

    g1.loadGraph({{5, 6}, {9, 10}});
    g2.loadGraph({{1, 2}, {3, 4}});

    ariel::Graph diff = g1 - g2;
    const auto& diffMatrix = diff.getAdjacencyMatrix();

    assert(diffMatrix[0][0] == 4);
    assert(diffMatrix[0][1] == 4);
    assert(diffMatrix[1][0] == 6);
    assert(diffMatrix[1][1] == 6);

    std::cout << "testGraphSubtraction passed!" << std::endl;
}

void testGraphSubtractionAssignment() {
    ariel::Graph g1, g2;

    g1.loadGraph({{5, 6}, {9, 10}});
    g2.loadGraph({{1, 2}, {3, 4}});

    g1 -= g2;
    const auto& resultMatrix = g1.getAdjacencyMatrix();

    assert(resultMatrix[0][0] == 4);
    assert(resultMatrix[0][1] == 4);
    assert(resultMatrix[1][0] == 6);
    assert(resultMatrix[1][1] == 6);

    std::cout << "testGraphSubtractionAssignment passed!" << std::endl;
}

void testUnaryPlus() {
    ariel::Graph g;

    g.loadGraph({{1, -2}, {-3, 4}});

    ariel::Graph pos = +g;
    const auto& posMatrix = pos.getAdjacencyMatrix();

    assert(posMatrix[0][0] == 1);
    assert(posMatrix[0][1] == -2);
    assert(posMatrix[1][0] == -3);
    assert(posMatrix[1][1] == 4);

    std::cout << "testUnaryPlus passed!" << std::endl;
}

void testUnaryMinus() {
    ariel::Graph g;

    g.loadGraph({{1, -2}, {-3, 4}});

    ariel::Graph neg = -g;
    const auto& negMatrix = neg.getAdjacencyMatrix();

    assert(negMatrix[0][0] == -1);
    assert(negMatrix[0][1] == 2);
    assert(negMatrix[1][0] == 3);
    assert(negMatrix[1][1] == -4);

    std::cout << "testUnaryMinus passed!" << std::endl;
}
void testGraphAdditionDifferentSizes() {
    ariel::Graph g1, g2;

    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1}}); // Smaller size graph

    try {
        ariel::Graph sum = g1 + g2;
        assert(false); // Should not reach this point
    } catch (const std::invalid_argument& e) {
        std::cout << "testGraphAdditionDifferentSizes passed with expected exception: " << e.what() << std::endl;
    } catch (...) {
        assert(false); // Wrong exception type caught
    }
}

void testGraphSubtractionZeroEdges() {
    ariel::Graph g1, g2;

    g1.loadGraph({{0, 0}, {0, 0}});
    g2.loadGraph({{0, 0}, {0, 0}});

    ariel::Graph diff = g1 - g2;
    const auto& diffMatrix = diff.getAdjacencyMatrix();

    assert(diffMatrix[0][0] == 0);
    assert(diffMatrix[0][1] == 0);
    assert(diffMatrix[1][0] == 0);
    assert(diffMatrix[1][1] == 0);

    std::cout << "testGraphSubtractionZeroEdges passed!" << std::endl;
}

void testGraphMultiplicationByScalarEdgeCases() {
    ariel::Graph g;

    g.loadGraph({{INT_MAX, -INT_MAX}, {INT_MIN, INT_MAX}});

    ariel::Graph scaled = g * 2;  // Potential overflow
    const auto& scaledMatrix = scaled.getAdjacencyMatrix();

    // Assuming no overflow handling - adjust assertions based on your implementation specifics
    assert(scaledMatrix[0][0] == INT_MIN);  // INT_MAX * 2 overflows to INT_MIN (undefined behavior)
    assert(scaledMatrix[0][1] == 0);       // -INT_MAX * 2 wraps around to 0 (undefined behavior)
    assert(scaledMatrix[1][0] == 0);       // INT_MIN * 2 is undefined, typically 0
    assert(scaledMatrix[1][1] == INT_MIN);

    std::cout << "testGraphMultiplicationByScalarEdgeCases passed!" << std::endl;
}

int main() {
    // Arithmetic operators
    testGraphAddition();
    testGraphAdditionAssignment();
    testGraphSubtraction();
    testGraphSubtractionAssignment();
    testUnaryPlus();
    testUnaryMinus();
    testGraphAdditionDifferentSizes();
	testGraphSubtractionZeroEdges();
	

    std::cout << "All tests passed!" << std::endl;
    return 0;
}