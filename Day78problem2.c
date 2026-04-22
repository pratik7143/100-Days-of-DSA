void dfs(int u, List** adj, int visited[], int disc[], int low[], int parent[], int ap[]) {
    visited[u] = 1;
    disc[u] = low[u] = timer++;
    int children = 0;
    List* temp = adj[u];
    while (temp != NULL) {
        int v = temp->data;
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v, adj, visited, disc, low, parent, ap);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            if (parent[u] == -1 && children > 1)
                ap[u] = 1;
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }

        temp = temp->next;
    }
}
