class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int cnt = 0;
        for(int i=0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j+1; k < n; ++k){
                    if((r[i] < r[j] and r[j] < r[k]) || (r[i] > r[j] and r[j] > r[k])) cnt++;
                }
            }
        }
        return cnt;
    }
};