323889451
ghia48.serhan@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <queue>
#include <string>

namespace Algorithms {
    bool isConnected(const ariel::Graph& g);
    std::string isContainsCycle(const ariel::Graph& g);
    std::string shortestPath(const ariel::Graph& g, int start, int end);
    std::string isBipartite(const ariel::Graph& g);
    std::string negativeCycle(const ariel::Graph& g);
    // Other algorithm function declarations will be added here
}

#endif