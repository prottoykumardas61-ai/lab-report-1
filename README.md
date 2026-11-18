# lab-report-1


# Graph 

## Project Overview
This project is developed using the C programming language. It analyzes an undirected and weighted graph using different graph algorithms.

The program finds paths between two vertices and checks how removing an edge affects the network.

## Algorithms Used
1. **Dijkstra's Algorithm** – Finds the shortest path between two vertices.
2. **Kruskal's Algorithm** – Finds the Minimum Spanning Tree (MST).
3. **Prim's Algorithm** – Finds the Minimum Spanning Tree (MST).
4. **BFS (Breadth First Search)** – Finds a path and calculates its cost.
5. **Find (Union-Find)** – Helps Kruskal's algorithm detect cycles.

## Main Features
- Takes vertices and edges as input.
- Creates an undirected weighted graph.
- Finds the shortest path using Dijkstra.
- Finds paths using Kruskal and Prim.
- Displays the path and total cost.
- Removes a selected edge from the graph.
- Checks whether the updated graph is connected.
- Displays updated paths after removing an edge.

## Input Format

First, enter the number of vertices and edges.

Then enter each edge in this format:

```text
u v weight
```

Finally, enter:

```text
source destination u v
```

Here:
- `source` = Starting vertex
- `destination` = Ending vertex
- `u, v` = Edge to remove

**Note:** Vertices start from 0.

## Example Input

```text
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
3 4 2
0 4 1 2
```

## Example Output

```text
--- Original Graph ---
Shortest Path: 0 -> 1 -> 2 -> 3 -> 4 (Cost: 8)
Kruskal Path: 0 -> 1 -> 2 -> 3 -> 4 (Cost: 8)
Prim Path: 0 -> 1 -> 2 -> 3 -> 4 (Cost: 8)

After Removing Edge (1,2):
Updated Shortest Path: 0 -> 1 -> 3 -> 4 (Cost: 11)
Updated Kruskal Path: 0 -> 1 -> 3 -> 4 (Cost: 11)
Updated Prim Path: 0 -> 1 -> 3 -> 4 (Cost: 11)
```

## How to Run

### Step 1: Compile the Program

```bash
gcc main.c -o graph
```

### Step 2: Run the Program

```bash
./graph
```

For Windows:

```bash
graph.exe
```

## Programming Language
- C Programming Language
- Graph Data Structure
- Graph Algorithms

## Conclusion
This project helps us understand graph algorithms and how they work in real-life network systems. It also shows how removing an edge can affect network connectivity and paths.


## Project Overview
This project is developed using the C programming language. It analyzes an undirected and weighted graph using different graph algorithms.

The program finds paths between two vertices and checks how removing an edge affects the network.

## Algorithms Used
1. **Dijkstra's Algorithm** – Finds the shortest path between two vertices.
2. **Kruskal's Algorithm** – Finds the Minimum Spanning Tree (MST).
3. **Prim's Algorithm** – Finds the Minimum Spanning Tree (MST).
4. **BFS (Breadth First Search)** – Finds a path and calculates its cost.
5. **Find (Union-Find)** – Helps Kruskal's algorithm detect cycles.

## Main Features
- Takes vertices and edges as input.
- Creates an undirected weighted graph.
- Finds the shortest path using Dijkstra.
- Finds paths using Kruskal and Prim.
- Displays the path and total cost.
- Removes a selected edge from the graph.
- Checks whether the updated graph is connected.
- Displays updated paths after removing an edge.

## Input Format

First, enter the number of vertices and edges.

Then enter each edge in this format:

```text
u v weight
```

Finally, enter:

```text
source destination u v
```

Here:
- `source` = Starting vertex
- `destination` = Ending vertex
- `u, v` = Edge to remove

**Note:** Vertices start from 0.

## Example Input

```text
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
3 4 2
0 4 1 2
```

## Example Output

```text
--- Original Graph ---
Shortest Path: 0 -> 1 -> 2 -> 3 -> 4 (Cost: 8)
Kruskal Path: 0 -> 1 -> 2 -> 3 -> 4 (Cost: 8)
Prim Path: 0 -> 1 -> 2 -> 3 -> 4 (Cost: 8)

After Removing Edge (1,2):
Updated Shortest Path: 0 -> 1 -> 3 -> 4 (Cost: 11)
Updated Kruskal Path: 0 -> 1 -> 3 -> 4 (Cost: 11)
Updated Prim Path: 0 -> 1 -> 3 -> 4 (Cost: 11)
```

## How to Run

### Step 1: Compile the Program

```bash
gcc main.c -o graph
```

### Step 2: Run the Program

```bash
./graph
```

For Windows:

```bash
graph.exe
```

## Programming Language
- C Programming Language
- Graph Data Structure
- Graph Algorithms

## Conclusion
This project helps us understand graph algorithms and how they work in real-life network systems. It also shows how removing an edge can affect network connectivity and paths.
