class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>m;
        int maxi = -1;
        for(auto &c : nums){
            m[c]++;
        }
        for(auto &p : m){
            maxi = max(maxi,p.second);
        }
        vector<vector<int>>mat(maxi);
        for(auto &p : m){
            for(int i=0; i < p.second; ++i){
                mat[i].push_back(p.first);
            }
        }
        return mat;
    }
};