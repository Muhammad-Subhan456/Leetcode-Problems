class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> AdjList(n+2);
        for(int i=0 ; i < n; ++i){
            AdjList[edges[i][0]].push_back(edges[i][1]);
            AdjList[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0; i < AdjList.size(); ++i){
           if(AdjList[i].size()>1) return i;
        }
        return 0;
        
    }
};