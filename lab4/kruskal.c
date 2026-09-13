/*
DAA LAB - Experiment 4
Greedy Algorithm: Kruskal's Minimum Spanning Tree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compareEdges(const void *a, const void *b) {
    const Edge *e1 = a;
    const Edge *e2 = b;
    return e1->weight - e2->weight;
}

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSets(int parent[], int rank[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a == b) return;

    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[a] > rank[b]) parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main(void) {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || E < 0) return 0;

    Edge *edges = malloc((size_t)E * sizeof(Edge));
    int *parent = malloc((size_t)V * sizeof(int));
    int *rank = calloc((size_t)V, sizeof(int));

    if (!edges || !parent || !rank) return 1;

    printf("Enter each edge as: source destination weight\n");
    printf("Use vertex numbers 0 to %d.\n", V - 1);

    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    qsort(edges, E, sizeof(Edge), compareEdges);

    for (int i = 0; i < V; i++) parent[i] = i;

    int selected = 0, totalWeight = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < E && selected < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, rank, u, v);
            printf("%d -- %d  weight = %d\n", u, v, edges[i].weight);
            totalWeight += edges[i].weight;
            selected++;
        }
    }

    if (selected != V - 1)
        printf("MST does not exist because the graph is disconnected.\n");
    else
        printf("Total MST weight = %d\n", totalWeight);

    free(edges);
    free(parent);
    free(rank);
    return 0;
}
