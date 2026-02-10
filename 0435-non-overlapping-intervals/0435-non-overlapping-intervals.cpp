class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[](auto &a, auto &b){
            return a[1] < b[1];
        });
        int cnt = 0, last = -1e9;
        for(auto &i : in){
            if(i[0] >= last){
                cnt++; last = i[1];
            }
        }
        return (in.size()-cnt);

    }
};