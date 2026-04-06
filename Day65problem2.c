#include <stdbool.h>
#include <stdlib.h>
// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}
// Union function
bool unionSet(int parent[], int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu == pv)
        return true; // cycle found
    parent[pu] = pv;
    return false;
}

bool isCycle(int edges[][2], int E, int V) {
    int* parent = (int*)malloc(V * sizeof(int));

    // Initialize
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Process edges
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (unionSet(parent, u, v))
            return true;
    }

    return false;
}
