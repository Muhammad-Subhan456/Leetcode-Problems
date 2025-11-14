class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto &e : times){
           int u = e[0]; int v = e[1]; int w = e[2];
           adj[u].push_back({v,w});
        }
    auto dijkstra = [&](){
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            for(auto [adjNode,edgeWeight] : adj[node]){
                if(dis+edgeWeight < dist[adjNode]){
                     dist[adjNode] = dis+edgeWeight;
                     pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    };
    vector<int>ans = dijkstra();
    int sum=0;
    for(int i=1; i <= n; ++i){
        if(ans[i] == INT_MAX) return -1;
        sum = max(sum,ans[i]);
    }
    return sum;

    }
};