class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n + 1, 0);
        int ans = 0;
        function<void(int, int&, int&)> dfs = [&](int node, int& nodes,
                                                  int& deg) {
            vis[node] = 1;
            nodes++;
            deg += adj[node].size();

            for (int u : adj[node]) {
                if (!vis[u]) {
                    dfs(u, nodes, deg);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int nodes = 0;
                int deg = 0;
                dfs(i, nodes, deg);
                int edges = deg / 2;
                if (edges == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};