323889451
ghia48.serhan@gmail.com
#include <iostream>
#include <cassert>
#include "Graph.hpp"

void testEquality() {
    ariel::Graph g1, g2, g3;

    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1, 2}, {3, 4}});
    g3.loadGraph({{2, 3}, {4, 5}});

    assert(g1 == g2);
    assert(!(g1 == g3));

    std::cout << "testEquality passed!" << std::endl;
}

void testInequality() {
    ariel::Graph g1, g2, g3;

    g1.loadGraph({{1, 2}, {3, 4}});
    g2.loadGraph({{1, 2}, {3, 4}});
    g3.loadGraph({{2, 3}, {4, 5}});

    assert(g1 != g3);
    assert(!(g1 != g2));

    std::cout << "testInequality passed!" << std::endl;
}

void testGreater() {
    ariel::Graph g1, g2, g3;

    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 2}, {2, 0}});
    g3.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

    assert(g3 > g1);  // g3 has more edges and vertices
    assert(!(g1 > g2));  // Same number of edges, different weights
    assert(g3 > g2);  // g3 has more vertices and edges

    std::cout << "testGreater passed!" << std::endl;
}

void testLess() {
    ariel::Graph g1, g2, g3;

    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});
    g3.loadGraph({{0, 2}, {2, 0}});

    assert(g1 < g2);  // g2 has more vertices and edges
    assert(!(g3 < g1));  // Same number of edges and vertices, different weights

    std::cout << "testLess passed!" << std::endl;
}

void testGreaterOrEqual() {
    ariel::Graph g1, g2, g3;

    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 1}, {1, 0}});
    g3.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

    assert(g1 >= g2);  // Exactly equal
    assert(g3 >= g1);  // g3 has more vertices and edges
    assert(!(g1 >= g3));  // g1 has fewer vertices and edges

    std::cout << "testGreaterOrEqual passed!" << std::endl;
}

void testLessOrEqual() {
    ariel::Graph g1, g2, g3;

    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 1}, {1, 0}});
    g3.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

    assert(g1 <= g2);  // Exactly equal
    assert(!(g3 <= g1));  // g3 has more vertices and edges
    assert(g1 <= g3);  // g1 has fewer vertices and edges

    std::cout << "testLessOrEqual passed!" << std::endl;
}
void testEmptyGraphs() {
    ariel::Graph empty1, empty2;
    empty1.loadGraph({});
    empty2.loadGraph({});
    assert(empty1 == empty2);
    assert(!(empty1 != empty2));
    assert(!(empty1 > empty2));
    assert(!(empty1 < empty2));
    assert(empty1 >= empty2);
    assert(empty1 <= empty2);
    std::cout << "testEmptyGraphs passed!" << std::endl;
}
void testZeroWeightEdges() {
    ariel::Graph g1, g2;
    g1.loadGraph({{0, 1}, {1, 0}});
    g2.loadGraph({{0, 0}, {0, 0}}); // Completely disconnected graph
    assert(g1 != g2);
    assert(g1 > g2);  // g1 actually has edges, whereas g2 does not
    std::cout << "testZeroWeightEdges passed!" << std::endl;
}
void testGraphsWithDifferentWeights() {
    ariel::Graph g1, g2;
    g1.loadGraph({{1, 2}, {2, 1}});
    g2.loadGraph({{2, 1}, {1, 2}});  // Same edges but different weights
    assert(g1 != g2);
    assert(!(g1 == g2));
    std::cout << "testGraphsWithDifferentWeights passed!" << std::endl;
}

int main() {
    testEquality();
    testInequality();
    testGreater();
    testLess();
    testGreaterOrEqual();
    testLessOrEqual();
    testEmptyGraphs();
    testZeroWeightEdges();
    testGraphsWithDifferentWeights();
    return 0;
}
