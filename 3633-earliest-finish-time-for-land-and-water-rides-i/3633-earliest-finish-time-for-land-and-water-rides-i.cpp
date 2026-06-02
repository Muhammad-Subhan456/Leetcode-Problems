class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size(), m = ws.size();
        int mini = INT_MAX;
        for(int i=0; i < n; ++i){
            int land = ls[i] + ld[i];
            for(int j=0; j < m; ++j){
                int startWater = max(land, ws[j]);
                mini = min(mini, startWater+wd[j]);
            }
        }
        for (int i = 0; i < m; i++) {
            int waterFinish = ws[i] + wd[i];

            for (int j = 0; j < n; j++) {
                int startLand = max(waterFinish, ls[j]);
                mini = min(mini, startLand + ld[j]);
            }
        }
        return mini;
    }
};