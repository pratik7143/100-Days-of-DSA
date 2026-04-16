#include <stdbool.h>
bool dfs(int node, int** graph, int* graphColSize, int* color, int currColor) {
    color[node] = currColor;
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (color[neighbor] == -1) {
            // Color neighbor with opposite color
            if (!dfs(neighbor, graph, graphColSize, color, 1 - currColor)) {
                return false;
            }
        } else if (color[neighbor] == currColor) {
            // Conflict found
            return false;
        }
    }
    return true;
}
bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];

    // Initialize all nodes as unvisited
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }
    // Handle disconnected graph
    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            if (!dfs(i, graph, graphColSize, color, 0)) {
                return false;
            }
        }
    }
    return true;
}
