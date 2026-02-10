class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        ans.push_back(in[0]);
        for(int i=1;i < in.size(); ++i){
            if(ans.back()[1] < in[i][0] ) ans.push_back(in[i]); // 2 separate intervals
            else ans.back()[1] = max(ans.back()[1],in[i][1]) ; // 2 overlapping intervals,merge them
        }
        return ans;
        
    }
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        in.push_back(ni);
        sort(in.begin(),in.end());
        return merge(in);
    }
};