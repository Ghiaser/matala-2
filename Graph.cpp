323889451
ghia48.serhan@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <numeric>  // Include this for std::accumulate

namespace ariel {
    Graph::Graph() : numVertices(0), numEdges(0) {}

    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
        int rows = graph.size();
        int cols = rows > 0 ? graph[0].size() : 0;

        if (rows != cols) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        adjacencyMatrix = graph;
        numVertices = rows;
        numEdges = 0;

        for (int i = 0; i < numVertices; ++i) {
            for (int j =0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    ++numEdges;
                }
            }
        }
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
    }

    int Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    // Implementing arithmetic operations
    Graph Graph::operator+(const Graph& other) const {
        if (this->numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must have the same number of vertices to add.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = this->adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    Graph& Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }

    Graph Graph::operator-(const Graph& other) const {
        if (this->numVertices != other.numVertices) {
            throw std::invalid_argument("Graphs must have the same number of vertices to subtract.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = this->adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
            }
        }
        return result;
    }

    Graph& Graph::operator-=(const Graph& other) {
        *this = *this - other;
        return *this;
    }

    Graph Graph::operator+() const {
        return *this;
    }

    Graph Graph::operator-() const {
        Graph result;
        result.numVertices = this->numVertices;
        result.adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjacencyMatrix[i][j] = -this->adjacencyMatrix[i][j];
            }
        }
        return result;
    }
       bool Graph::operator==(const Graph& other) const {
        // First check if the number of vertices and edges are the same
        if (this->numVertices != other.numVertices || this->numEdges != other.numEdges) {
            return false;
        }

        // Check if all edges and their weights are the same
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (this->adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }
     bool Graph::operator>(const Graph& other) const {
        // Check if G1 is a subgraph of G2
        if (this->numVertices <= other.numVertices) {
            bool isSubgraph = true;
            for (int i = 0; i < this->numVertices; i++) {
                for (int j = 0; j < this->numVertices; j++) {
                    if (this->adjacencyMatrix[i][j] > other.adjacencyMatrix[i][j]) {
                        isSubgraph = false;
                        break;
                    }
                }
                if (!isSubgraph) break;
            }
            if (isSubgraph) return false;
        }

        // Neither graph is exactly contained in the other
        if (this->numEdges != other.numEdges) {
            return this->numEdges > other.numEdges;
        } else {
            return this->numVertices > other.numVertices;
        }
    }

    bool Graph::operator<(const Graph& other) const {
        return other > *this;
    }

    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    bool Graph::operator<=(const Graph& other) const {
        return !(*this > other);
    }
        // Prefix increment
 #include <climits>  // Needed for INT_MAX and INT_MIN

Graph& Graph::operator++() {
    for (auto& row : adjacencyMatrix) {
        for (auto& weight : row) {
            if (weight != 0 && weight != INT_MAX) {  // Check not to increment INT_MAX
                ++weight;
            }
        }
    }
    return *this;
}

// Postfix increment
Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);  // Use the prefix increment
    return temp;
}

Graph& Graph::operator--() {
    for (auto& row : adjacencyMatrix) {
        for (auto& weight : row) {
            if (weight != 0 && weight != INT_MIN) {  // Check not to decrement INT_MIN
                --weight;
            }
        }
    }
    return *this;
}

// Postfix decrement
Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);  // Use the prefix decrement
    return temp;
}

Graph& Graph::operator*=(int scalar) {
    for (auto& row : this->adjacencyMatrix) {
        for (auto& weight : row) {
            // Check for potential overflow or underflow before multiplying
            if (scalar != 0 && ((weight > 0 && weight > INT_MAX / scalar) || (weight < 0 && weight < INT_MIN / scalar))) {
                // Set weight to INT_MAX or INT_MIN based on the sign of scalar
                weight = scalar > 0 ? (weight > 0 ? INT_MAX : INT_MIN) : (weight > 0 ? INT_MIN : INT_MAX);
            } else {
                weight *= scalar;
            }
        }
    }
    return *this;
}

Graph Graph::operator*(int scalar) const {
    Graph result;
    result.numVertices = this->numVertices;
    result.adjacencyMatrix = this->adjacencyMatrix;
    for (auto& row : result.adjacencyMatrix) {
        for (auto& weight : row) {
            // Similar check as in operator*= for safe multiplication
            if (scalar != 0 && ((weight > 0 && weight > INT_MAX / scalar) || (weight < 0 && weight < INT_MIN / scalar))) {
                weight = scalar > 0 ? (weight > 0 ? INT_MAX : INT_MIN) : (weight > 0 ? INT_MIN : INT_MAX);
            } else {
                weight *= scalar;
            }
        }
    }
    return result;
}
Graph Graph::operator*(const Graph& other) const {
    if (this->numVertices != other.numVertices) {
        throw std::invalid_argument("Graphs must have the same number of vertices to multiply.");
    }

    Graph result;
    result.numVertices = this->numVertices;
    result.adjacencyMatrix.resize(this->numVertices, std::vector<int>(this->numVertices, 0));

    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            long long sum = 0;
            for (int k = 0; k < this->numVertices; ++k) {
                long long product = (long long)this->adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                if ((sum > 0 && product > INT_MAX - sum) || (sum < 0 && product < INT_MIN - sum)) {
                    sum = product > 0 ? INT_MAX : INT_MIN;
                    break;
                }
                sum += product;
            }
            result.adjacencyMatrix[i][j] = (sum > INT_MAX) ? INT_MAX : (sum < INT_MIN ? INT_MIN : sum);
        }
    }

    return result;
}

     std::ostream& operator<<(std::ostream& os, const Graph& g) {
        os << "Graph with " << g.numVertices << " vertices and " << g.numEdges << " edges.\n";
        os << "Adjacency Matrix:\n";
        for (const auto& row : g.adjacencyMatrix) {
            for (const auto& value : row) {
                os << value << " "; // Simply separate values by space
            }
            os << '\n'; // New line after each row
        }
        return os;
    }
    
}
