class Solution {
public:

    void unionByRank(int u, int v,vector<int>&parent, vector<int>&rank) 
    {
        int ulp_u = findUltiParent(u,parent);
        int ulp_v = findUltiParent(v,parent);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    int findUltiParent(int node,vector<int>&parent) {
        if (node == parent[node]) return node;
        return parent[node] = findUltiParent(parent[node],parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        for(auto&x : edges){
            int a = x[0];
            int b = x[1];
        if(findUltiParent(a,parent) == findUltiParent(b,parent)){
            return {a,b};
        }
        else{
            unionByRank(a,b,parent,rank);
        }

        }
        return {};

    }
};