class Solution {
public:
    vector<int> topoSort(int V,int E,vector<vector<int>> &edges)
{
    // create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0; i < E; ++i){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    //find all the indegrees
    vector<int>indegree(V);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }
    
    // push all nodes with 0 indegree
    queue<int>q;
    for(int i=0; i < V; ++i){
        if(indegree[i]==0) q.push(i);
    }

    // Do Bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        // update indegree of neighbours

        for(auto neighbour : adj[front]){
            // reduce the indegrees by 1
            indegree[neighbour]--;
            // if indegree become zero push it in the queue
            if(indegree[neighbour]==0) q.push(neighbour);
        }
    }

    return ans;
}  
    vector<int> findOrder(int v, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<int>ans = topoSort(v,E,edges);
        //for(auto c : ans) cout << c << " ";
        reverse(ans.begin(),ans.end());
        if(v == ans.size()) return ans;
        return {};  
    }
};