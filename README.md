# Graph 

## Project Overview
This project is developed using the C programming language to analyze a connected, undirected, weighted graph.

The program uses different graph algorithms to find the shortest path, construct Minimum Spanning Trees (MST), and analyze the effect of removing an edge from the graph.

It compares different network configurations and displays the paths and their total costs.

## Algorithms Used

1. **BFS (Breadth-First Search)**
   - Finds a path between two vertices.
   - Calculates the total cost of the selected path.

2. **Dijkstra's Algorithm**
   - Finds the shortest path between a source and destination.
   - Calculates the minimum path cost.

3. **Kruskal's Algorithm**
   - Constructs a Minimum Spanning Tree (MST).
   - Selects edges based on their weights.

4. **Prim's Algorithm**
   - Constructs a Minimum Spanning Tree (MST).
   - Selects the minimum-weight edges to connect all vertices.

5. **Edge Removal**
   - Removes a selected edge from the graph.
   - Updates the graph.
   - Checks whether the graph is still connected.
   - Runs the algorithms again on the updated graph.

## Features

- Takes the number of vertices and edges as input.
- Accepts weighted graph edges.
- Finds the shortest path using Dijkstra's algorithm.
- Builds MST using Prim's and Kruskal's algorithms.
- Displays paths and their total costs.
- Removes a selected edge from the graph.
- Checks graph connectivity after edge removal.
- Displays updated paths and costs.
- Handles invalid input.

## Technologies Used

- Programming Language: C
- Compiler: GCC
- Concepts: Graph, BFS, Dijkstra, MST, Prim, Kruskal, Union-Find

## Input Format

First, enter the number of vertices and edges.

Then enter each edge in the following format:


## Output

The program displays:

- Original graph shortest path.
- Kruskal MST path.
- Prim MST path.
- Updated shortest path after removing an edge.
- Updated Kruskal MST path.
- Updated Prim MST path.
- Connectivity status of the updated graph.




## Learning Outcomes

Through this project, we learned:

- How to represent a weighted graph using an adjacency matrix.
- How BFS works in graph traversal.
- How Dijkstra's algorithm finds the shortest path.
- How Prim's and Kruskal's algorithms construct MST.
- How Union-Find works in Kruskal's algorithm.
- How removing an edge affects graph connectivity.
- How to implement graph algorithms using C.

## Conclusion

This project demonstrates the practical implementation of different graph algorithms in C. It helps us understand shortest paths, Minimum Spanning Trees, and graph connectivity. It also shows how removing an edge can affect a network's structure and communication paths.

---

**Language:** C  
**Project Type:** Data Structures and Algorithms
