class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int n = in.size();
        int cnt = 0;  
       // sort(in.begin(),in.end());
        for(int i=0; i < n; ++i){
            for(int j=0; j < n; ++j){
                if(i==j) continue;
                if(in[i][0] >= in[j][0] && in[i][1] <= in[j][1]) {
                cnt++;
                break;
                }
            }
        }
        return n-cnt;
        
    }
};