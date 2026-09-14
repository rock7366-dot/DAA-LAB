# Experiment 4: Kruskal's Algorithm

### Aim
To find the Minimum Spanning Tree (MST) of a connected weighted undirected graph using the greedy approach.

### Algorithm
1. Sort all edges in non-decreasing order of weight.
2. Initialize each vertex as a separate set.
3. Pick the smallest remaining edge.
4. If its endpoints belong to different sets, include the edge in the MST.
5. Union the two sets.
6. Repeat until `V - 1` edges are selected.

### Data structure
Disjoint Set Union (Union-Find) with path compression and union by rank.

### Complexity
- Sorting edges: **O(E log E)**
- Union-Find operations: near-linear, `O(E α(V))`
- Overall: **O(E log E)**

### Compilation
```bash
gcc kruskal.c -o kruskal
./kruskal
```
