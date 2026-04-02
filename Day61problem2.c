#include <stdbool.h>
// DFS function
void dfs(int** isConnected, int n, int city, bool* visited) {
    visited[city] = true;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i, visited);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int provinces = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i, visited);
            provinces++; // new province found
        }
    }
    return provinces;
}
