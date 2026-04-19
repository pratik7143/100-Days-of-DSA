#include <stdio.h>
#include <stdlib.h>
int timer = 0;
void dfs(int u, int parent, int* disc, int* low,
         int** adj, int* adjSize,
         int** result, int* returnSize) {
    disc[u] = low[u] = timer++;
    
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        
        if (v == parent) continue;
        
        if (disc[v] == -1) {
            dfs(v, u, disc, low, adj, adjSize, result, returnSize);
            
            low[u] = low[u] < low[v] ? low[u] : low[v];
            
            if (low[v] > disc[u]) {
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {
    
    // Build adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    
    // First count degrees
    for (int i = 0; i < connectionsSize; i++) {
        adjSize[connections[i][0]]++;
        adjSize[connections[i][1]]++;
    }

    // Allocate exact memory
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // reset for filling
    }
    // Fill adjacency list
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }
    
    // Initialize arrays
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    *returnSize = 0;
    
    dfs(0, -1, disc, low, adj, adjSize, result, returnSize);
    
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    
    return result;
}
