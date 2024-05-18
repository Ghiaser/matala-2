323889451
ghia48.serhan@gmail.com

compile : g++ Demo.cpp Graph.cpp Algorithms.cpp  
Run the Executables:
After compilation, you can run each program individually by typing the following in the terminal:

For adding and subtracting tests:
./tests_add_sub

For equality and inequality tests:

./tests_equal_inequal

For increment and decrement tests:
./tests_inc_dec

For multiplication tests:
./tests_multiply

For print functionality tests:

./tests_print

For running algorithms :
./demo
Cleaning up:
To remove all compiled object files and executables, execute:
make clean




Constructor: Graph()
Purpose: Initializes a new graph with zero vertices and zero edges.

loadGraph(const std::vector<std::vector<int>>& graph)
Purpose: Loads a graph from a square adjacency matrix where the presence of an edge between two vertices is indicated by a nonzero value.
Parameters: graph - A square matrix representing the adjacency of the vertices.
Exceptions: Throws std::invalid_argument if the input matrix is not square.

printGraph() const
Purpose: Outputs the number of vertices and edges in the graph to the standard output.

getNumVertices() const
Purpose: Returns the number of vertices in the graph.

getNumEdges() const
Purpose: Returns the number of edges in the graph.

getAdjacencyMatrix() const
Purpose: Returns the adjacency matrix of the graph. This method also checks if the graph is directed by comparing elements at i,j and j,i for asymmetry




# Graph Class Operator Implementations

This README provides an overview of the operator implementations in the Graph class. 
The Graph class represents a graph using an adjacency matrix and supports various arithmetic and comparison operations.

## Arithmetic Operators

### Addition (`+` and `+=`)
- The `+` operator adds two graphs element-wise. Both graphs must have the same number of vertices.
- The `+=` operator adds another graph to the current graph in-place.

### Subtraction (`-` and `-=`)
- The `-` operator subtracts two graphs element-wise. Both graphs must have the same number of vertices.
- The `-=` operator subtracts another graph from the current graph in-place.

### Unary Plus (`+`)
- The unary `+` operator returns a copy of the graph.

### Unary Minus (`-`)
- The unary `-` operator returns a new graph with negated edge weights.

### Multiplication (`*` and `*=`)
- The `*` operator multiplies the graph by a scalar value, scaling all edge weights.
- The `*=` operator multiplies the graph by a scalar value in-place.
- The `*` operator also supports matrix multiplication of two graphs. Both graphs must have the same number of vertices.

### Increment (`++`)
- The prefix `++` operator increments all non-zero edge weights by 1.
- The postfix `++` operator returns a copy of the graph and then increments all non-zero edge weights by 1.

### Decrement (`--`)
- The prefix `--` operator decrements all non-zero edge weights by 1.
- The postfix `--` operator returns a copy of the graph and then decrements all non-zero edge weights by 1.

## Comparison Operators

### Equality (`==`)
- The `==` operator checks if two graphs are equal by comparing their number of vertices, number of edges, and edge weights.

### Inequality (`!=`)
- The `!=` operator checks if two graphs are not equal.

### Greater Than (`>`)
- The `>` operator compares two graphs based on their structure and size.
- It checks if one graph is a subgraph of the other and compares the number of edges and vertices.

### Less Than (`<`)
- The `<` operator is the opposite of the `>` operator.

### Greater Than or Equal To (`>=`)
- The `>=` operator checks if one graph is greater than or equal to another graph.

### Less Than or Equal To (`<=`)
- The `<=` operator checks if one graph is less than or equal to another graph.

## I/O Operators

### Output (`<<`)
- The `<<` operator is overloaded to output the graph to a stream.
- It prints the number of vertices, number of edges, and the adjacency matrix.

## Notes
- The operators handle potential overflow and underflow situations by clamping the values to `INT_MAX` or `INT_MIN`.
- The operators throw `std::invalid_argument` exceptions if the graphs have incompatible sizes for the operation.

Please refer to the source code for the detailed implementation of each operator.




Algorithms Namespace Methods
isBipartite(const ariel::Graph& g)
Purpose: Determines if the graph is bipartite, i.e., can be colored using two colors such that no two adjacent vertices share the same color.
Parameters: g - The graph to check.
Returns: A string that either indicates the partition sets of vertices if the graph is bipartite ("The graph is bipartite: A={...}, B={...}") or "0" if the graph is not bipartite.

dfs(int current, int parent, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& path)
Purpose: Helper function for depth-first search to detect cycles in the graph.
Parameters:
current - Current vertex in the DFS.
parent - Parent vertex of the current vertex.
adj - Adjacency matrix of the graph.
visited - Vector to track visited vertices.
path - Vector to store the path traversed.
Returns: true if a cycle is found, false otherwise.

negativeCycle(const ariel::Graph& g)
Purpose: Detects if there is any negative weight cycle in the graph that is reachable from any vertex using the Bellman-Ford algorithm.
Parameters: g - The graph to check.
Returns: A descriptive string of the cycle if found ("Negative cycle found: ..."), or "No negative cycle found."

isContainsCycle(const ariel::Graph& g)
Purpose: Checks if there is any cycle in the graph.
Parameters: g - The graph to check.
Returns: A string representation of the cycle if found, or "0" if no cycle is found.

isConnected(const ariel::Graph& g)
Purpose: Determines if the graph is connected, i.e., there is a path from any vertex to every other vertex in the graph.
Parameters: g - The graph to check.
Returns: true if the graph is connected, false otherwise.

shortestPath(const ariel::Graph& g, int start, int end)
Purpose: Computes the shortest path from a start vertex to an end vertex using the Bellman-Ford algorithm.
Parameters:
g - The graph.
start - Starting vertex.
end - Ending vertex.
Returns: A string representing the shortest path ("start -> ... -> end") or "Graph contains a negative weight cycle" if such a cycle impacts the path, or "-1" if no path exists.

DEMO.cpp
this file is used to test the graph and algorithm classes with diffrent graphs .

