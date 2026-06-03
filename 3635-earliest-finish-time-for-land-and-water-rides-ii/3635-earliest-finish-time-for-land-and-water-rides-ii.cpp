class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size(), m = ws.size();
        int miniland = INT_MAX;
        // start from land
        for(int i=0; i < n; ++i){
            miniland = min(miniland , ls[i]+ld[i]);
        }
        int startwater = 0 , min1 = INT_MAX ;
        for(int i=0; i < m; ++i){
            startwater = max(miniland, ws[i]);
            min1 = min(min1, startwater + wd[i]);
        }
        int miniwater = INT_MAX;
        // start from water
        for(int i=0; i < m; ++i){
            miniwater = min(miniwater , ws[i]+wd[i]);
        }
        cout << miniwater;
        startwater = 0 ; int min2 = INT_MAX ;
        for(int i=0; i < n; ++i){
            startwater = max(miniwater, ls[i]);
            min2 = min(min2, startwater + ld[i]);
        }
        return min(min1,min2);

    }
};