class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> res;
        for (auto& e : invocations) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(n, 0);
        function<void(int)> dfs = [&](int node) -> void {
            vis[node] = 1;
            for (auto neig : adj[node]) {
                if (!vis[neig]) {
                    dfs(neig);
                }
            }
        };

        dfs(k);
        for (auto& e : invocations) {
            int u = e[0], v = e[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                ans.push_back(i);

        return ans;
    }
};