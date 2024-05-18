323889451
ghia48.serhan@gmail.com
/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{   

    cout << "graph 1" << endl;
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    
    g.printGraph();                                     // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
   cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
   cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << Algorithms::negativeCycle(g) << endl;     // Should print: "0" (false).
    cout << "graph 2" << endl;
    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.
 
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::negativeCycle(g) << endl;     // Should print: "0" (false).

    cout << "graph 3" << endl;
    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
   cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
   
  
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
        cout << Algorithms::negativeCycle(g) << endl;     // Should print: "0" (false).

  
     // Test Graph 2: Graph with multiple components, one of which is a cycle
    cout << "Graph 5" << endl;
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    g.loadGraph(graph5);
    g.printGraph();
      cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (no path).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "3->4->3" (cycle in the second component).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false), because of the isolated cycle.
        cout << Algorithms::negativeCycle(g) << endl;     // Should print: "0" (false).


    cout << "Graph 6" << endl;
     vector<vector<int>> graph6 = {
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    g.loadGraph(graph6);
    g.printGraph();
   cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 3) << endl; // Should print: "0->3".
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (no cycle, it's a tree).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0}, B={1, 2, 3}."
        cout << Algorithms::negativeCycle(g) << endl;     // Should print: "0" (false).

 cout << "Graph 7" << endl;
     // Test Graph 4: A complex graph with multiple cycles
    vector<vector<int>> graph7 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    g.loadGraph(graph7);
    g.printGraph();
      cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 3) << endl; // Should print: "0->4->3" (or another shortest path).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print a representation of one cycle, e.g., "0->1->2->3->4->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false), multiple cycles including odd-length cycles.
        cout << Algorithms::negativeCycle(g) << endl;     // Should print: "0" (false).

    cout << "Graph 8" << endl;
  // Creating a 4x4 matrix
    std::vector<std::vector<int>> graph8 = {
        {0,  1,  0,  0},
        {0,  0,  3,  0},
        {0,  0,  0,  2},
        {0, -6,  0,  0}
    };

    g.loadGraph(graph8);
    g.printGraph(); // This should output some details about the graph like number of vertices and edges.

    // Check for negative cycles
    std::cout << Algorithms::negativeCycle(g) << std::endl;




    cout << "Graph 11" << endl;
    vector<vector<int>> graph11 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    g.loadGraph(graph11);
    g.printGraph(); // Should print: "Graph with 3 vertices and 3 edges."
    cout << Algorithms::isContainsCycle(g) << endl; // Should print: cycle path like "0->1->2->0".
    cout << "Graph 12" << endl;
vector<vector<int>> graph12 = {
    {0, 1, 0},
    {0, 0, 1},
    {0, 0, 0}
};


g.loadGraph(graph12);
g.printGraph(); // Should print: "Graph with 3 vertices and 2 edges."
cout << Algorithms::isContainsCycle(g) << endl; // Should print: "0" (false).
cout << "Graph 13" << endl;
vector<vector<int>> graph13 = {
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0}
};
g.loadGraph(graph13);
g.printGraph(); // Should print: "Graph with 3 vertices and 3 edges."
cout << Algorithms::isContainsCycle(g) << endl; // Should print: cycle path like "0->1->2->0".


  // Unweighted Directed Graph
    g.loadGraph({
    {0, 1, 0, 1}, // Direct edge from 0 to 3 introduced
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
});
cout << "Shortest path (Unweighted Directed) from 0 to 3: " << Algorithms::shortestPath(g, 0, 3) << endl;
// Expected: "0 -> 3" since the direct route is a single hop

g.loadGraph({
    {0, 1, 1, 1}, // Direct edges from 0 to 2 and 0 to 3
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
});
g.printGraph();
cout << "Shortest path (Unweighted Undirected) from 0 to 3: " << Algorithms::shortestPath(g, 0, 3) << endl;
// Expected: "0 -> 3" since the direct route is also a single hop

    g.loadGraph({
    {0, 2, 0, 5}, // Direct path from 0 to 3 introduced with weight 5
    {0, 0, 2, 0},
    {0, 0, 0, 2},
    {1, 0, 0, 0}
});
g.printGraph();
cout << "Shortest path (Weighted Directed) from 0 to 3: " << Algorithms::shortestPath(g, 0, 3) << endl;
// Expected: "0 -> 1 -> 2 -> 3" because the total weight (6) is less than the direct path weight (5)


    // Weighted Undirected Graph
    g.loadGraph({ {0, 1, 0, 4},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {4, 0, 1, 0}});
    cout << "Shortest path (Weighted Undirected) from 0 to 3: " << Algorithms::shortestPath(g, 0, 3) << endl;

        
      cout << "final graph " << endl;
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }

}