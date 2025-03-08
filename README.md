# Efficient Computing Algorithms

## Overview
This repository contains optimized algorithmic solutions to computational problems, focusing on efficiency, scalability, and structured problem-solving. The implementations leverage key techniques such as **binary search**, **dynamic programming**, **graph algorithms**, and **shortest path computations** to solve real-world computational challenges.

## Features
- **Graph processing** using topological sorting and Dijkstra’s algorithm.
- **Dynamic programming** for efficient path counting and optimization.
- **Binary search** for resource allocation problems.
- **Greedy and heuristic approaches** for combinatorial optimization.
- **Efficient memory management** for handling large-scale data.

## Project Structure
This project includes solutions to three computational challenges, each with a structured approach.

### **1. Path Counting in Directed Acyclic Graphs (`numarare.cpp`)**
This module determines the number of **elementary paths** shared between two directed acyclic graphs (DAGs). An elementary path is a sequence of distinct nodes connected by directed edges.
- **Approach:**
  - Read input and construct two adjacency list representations for the graphs.
  - Build a new graph containing only the edges common to both input graphs.
  - Apply **Kahn’s algorithm** for **topological sorting** of the common graph.
  - Use **dynamic programming** to count the number of elementary paths from the start node to the destination.
  - Compute results modulo \(10^9 + 7\) for numerical stability.
- **Time Complexity:** O(N + M), where N is the number of nodes and M is the number of edges.

### **2. Maximum Cities Visited in a Train Network (`trenuri.cpp`)**
This module calculates the maximum number of distinct cities that can be visited in a **directed acyclic graph** of train routes between cities.
- **Approach:**
  - Construct a **graph** using an unordered map to efficiently store city connections.
  - Use **Kahn’s algorithm** to obtain a **topological ordering** of the cities.
  - Apply **dynamic programming** to compute the maximum number of unique cities traversed from the source to the destination.
  - Efficiently manage city names stored as strings to maintain flexibility in graph operations.
- **Time Complexity:** O(N + M), ensuring efficient processing for large datasets.

### **3. Minimum Path Sum in Weighted Graph (`drumuri.cpp`)**
This module finds the minimum sum of paths from two source nodes (X and Y) to a common destination (Z) in a weighted directed graph.
- **Approach:**
  - Construct a **weighted adjacency list** representation of the graph.
  - Apply **Dijkstra’s algorithm** separately from X and Y to compute the shortest paths to Z.
  - Compute the **sum of the two shortest paths** to obtain the minimum required cost.
- **Time Complexity:** O((N + M) log N), where priority queues optimize the shortest path computations.

## Compilation and Execution
To compile the project, use:
```sh
make
```
This generates executables for each algorithm. To run a specific module:
```sh
./path_counting
./max_cities_traversed
./shortest_path_sum
```

## Memory Management
All implementations prioritize **efficient memory usage**, ensuring that dynamically allocated resources are properly managed and deallocated to prevent memory leaks.

## Summary
This project presents a set of **high-performance computing algorithms**, designed for large-scale computational challenges. The solutions focus on efficiency, modular implementation, and structured algorithmic thinking.

