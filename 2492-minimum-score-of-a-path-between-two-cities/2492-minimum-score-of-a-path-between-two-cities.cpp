class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        map<int,int>mp;
        for(auto &e : roads){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            mp[v] = w;
        }
        vector<bool> vis(n+1,false);
        function <void(int)> dfs = [&](int u){
            vis[u] = true;
            for(auto [v,w] : adj[u]){
                if(!vis[v]) dfs(v);
            }
        };
        dfs(1);
        int ans = INT_MAX;
        for(auto &e : roads){
            int u = e[0], v = e[1], w = e[2];
            if(vis[u] && vis[v]) ans = min(ans,w);
        }
        return ans;
    }
};