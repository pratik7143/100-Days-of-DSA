class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& vis) {
        vis[node] = true;
        for (auto it : revAdj[node]) {
            if (!vis[it]) {
                dfs2(it, revAdj, vis);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        // Step 1: Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        // Step 2: DFS and push to stack
        vector<bool> vis(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        // Step 3: Reverse graph
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                revAdj[it].push_back(i);
            }
        }
        // Step 4: DFS on reversed graph
        fill(vis.begin(), vis.end(), false);
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                dfs2(node, revAdj, vis);
                scc++;
            }
        }
        return scc;
    }
};
