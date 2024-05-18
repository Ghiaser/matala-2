323889451
ghia48.serhan@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int numVertices;
        int numEdges;

    public:
        Graph();
        void loadGraph(const std::vector<std::vector<int>>& graph);
        void printGraph() const;
        int getNumVertices() const;
        int getNumEdges() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator+() const; // Unary plus
        Graph operator-() const; // Unary minus
        // Comparison operators
         bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>=(const Graph& other) const;

         // Increment and decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int);  // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int);  // Postfix decrement
      Graph operator*(int scalar) const;
        Graph& operator*=(int scalar);
        Graph operator*(const Graph& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);

    };
    
}


#endif // GRAPH_HPP
