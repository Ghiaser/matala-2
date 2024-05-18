323889451
ghia48.serhan@gmail.com
#include "Algorithms.hpp"
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <limits>
#include <climits>
#include <string>
namespace Algorithms {
     
    std::string isBipartite(const ariel::Graph& g) {
        int numVertices = g.getNumVertices();
        std::vector<int> colors(numVertices, -1);  // -1 indicates uncolored, 0 and 1 are the two colors
        std::queue<int> queue;

        for (int i = 0; i < numVertices; ++i) {
            if (colors[i] == -1) {  // Check if the vertex is not colored yet
                colors[i] = 0;      // Color the first vertex with color 0
                queue.push(i);

                while (!queue.empty()) {
                    int current = queue.front();
                    queue.pop();

                    const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();
                    for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
                        if (adjacencyMatrix[current][neighbor] > 0) {  // Check for any positive weight
                            if (colors[neighbor] == -1) {  // If the neighbor is not colored
                                colors[neighbor] = 1 - colors[current];  // Color with the opposite color
                                queue.push(neighbor);
                            } else if (colors[neighbor] == colors[current]) {
                             
                                return "0";  // If two connected vertices have the same color, it's not bipartite
                            }
                        }
                    }
                }
            }
        }

        // If the graph is bipartite, return the sets of vertices by their colors
        std::vector<int> setA, setB;
        for (int v = 0; v < numVertices; ++v) {
            if (colors[v] == 0) setA.push_back(v);
            else if (colors[v] == 1) setB.push_back(v);
        }

        std::stringstream ss;
        ss << "The graph is bipartite: A={";
        for (size_t i = 0; i < setA.size(); ++i) {
            if (i > 0) ss << ", ";
            ss << setA[i];
        }
        ss << "}, B={";
        for (size_t i = 0; i < setB.size(); ++i) {
            if (i > 0) ss << ", ";
            ss << setB[i];
        }
        ss << "}";

        return ss.str();
    }
    bool dfs(int current, int parent, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& path) {
        visited[current] = true;
        path.push_back(current);

        for (int neighbor = 0; neighbor < adj.size(); ++neighbor) {
            if (adj[current][neighbor] > 0) {  // There is an edge
                if (!visited[neighbor]) {
                    if (dfs(neighbor, current, adj, visited, path)) {
                        return true;
                    }
                } else if (neighbor != parent) {  // Visited and not coming from the parent, cycle found
                    path.push_back(neighbor); // Add the connecting vertex to close the cycle
                    return true;
                }
            }
        }

        path.pop_back();  // No cycle found, backtrack
        return false;
    }
std::string negativeCycle(const ariel::Graph& g) {
    int numVertices = g.getNumVertices();
    const std::vector<std::vector<int>>& adjMatrix = g.getAdjacencyMatrix();
    
    // For storing the shortest path distances
    std::vector<int> dist(numVertices, INT_MAX);
    // For tracking the predecessor of each vertex to reconstruct paths
    std::vector<int> predecessor(numVertices, -1);
    
    int startVertex = 0; // You can start with any vertex
    dist[startVertex] = 0; // Starting vertex has distance 0 to itself
    
    // Relax all edges |V| - 1 times (standard Bellman-Ford)
    for (int i = 0; i < numVertices - 1; i++) {
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    predecessor[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                // A negative cycle found
                // Return the cycle using the predecessor array
                std::vector<int> cycle;
                int x = v;
                for (int i = 0; i < numVertices; i++) {
                    x = predecessor[x]; // Find a vertex in the cycle
                }

                // Extract the cycle path
                int y = x;
                do {
                    cycle.push_back(y);
                    y = predecessor[y];
                } while (y != x);
                cycle.push_back(x); // Complete the cycle by adding the start vertex again to show closure

                std::reverse(cycle.begin(), cycle.end());

                // Constructing the result string
                std::string result = "Negative cycle found: ";
                for (size_t i = 0; i < cycle.size(); i++) {
                    result += std::to_string(cycle[i]);
                    if (i < cycle.size() - 1) {
                        result += " -> ";
                    }
                }
                return result;
            }
        }
    }

    return "No negative cycle found.";
}




    std::string isContainsCycle(const ariel::Graph& g) {
        int numVertices = g.getNumVertices();
        std::vector<bool> visited(numVertices, false);
        std::vector<int> path;

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                if (dfs(i, -1, g.getAdjacencyMatrix(), visited, path)) {
                    std::stringstream ss;
                    for (int j = 0; j < path.size(); ++j) {
                        if (j > 0) ss << "->";
                        ss << path[j];
                    }
                    return ss.str();  // Return the cycle path found
                }
            }
        }

        return "0";  // No cycle found
    }
    bool isConnected(const ariel::Graph& g) {
        int numVertices = g.getNumVertices();
        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;

        // Start BFS from vertex 0
        visited[0] = true;
        queue.push(0);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.pop();

            const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();

            for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (adjacencyMatrix[currentVertex][neighbor] != 0 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        // Check if all vertices were visited
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }

std::string shortestPath(const ariel::Graph& g, int start, int end) {
    int numVertices = g.getNumVertices();
    const std::vector<std::vector<int>>& adjMatrix = g.getAdjacencyMatrix();

    // Distance vector to store the minimum distance to each vertex from start.
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
    // Parent array to reconstruct the path.
    std::vector<int> predecessor(numVertices, -1);

    // Start vertex has distance 0 to itself
    dist[start] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < numVertices - 1; i++) {
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                if (adjMatrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    predecessor[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + adjMatrix[u][v] < dist[v]) {
                return "Graph contains a negative weight cycle";
            }
        }
    }

    // Reconstruct the path from end to start using the predecessor array
    if (dist[end] == std::numeric_limits<int>::max()) {
        return "-1"; // No path exists
    }

    std::vector<int> path;
    for (int at = end; at != -1; at = predecessor[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    // If the start vertex is not in the path, it means no path was found
    if (path[0] != start) {
        return "-1";
    }

    // Convert path to string format
    std::stringstream pathStream;
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) pathStream << " -> ";
        pathStream << path[i];
    }

    return pathStream.str();
}

    // Other algorithm function implementations will be added here
}