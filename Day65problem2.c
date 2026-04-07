#include <stdbool.h>
#include <stdlib.h>
int find(int parent[], int x) 
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}
bool unionSet(int parent[], int u, int v) 
{
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu == pv)
        return true;
    parent[pu] = pv;
    return false;
}
bool isCycle(int edges[][2], int E, int V)
{
    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = i;
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        if (unionSet(parent, u, v))
            return true;
    }
    return false;
}
