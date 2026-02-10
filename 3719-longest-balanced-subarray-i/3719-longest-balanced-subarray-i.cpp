class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0; i < n; ++i){
        set<int>o,e;
            for(int j=i; j < n; ++j){
                if(nums[j] & 1 ) o.insert(nums[j]);
                else e.insert(nums[j]);
                if(e.size() == o.size()) ans = max(ans,j-i+1);
            }

        }
        return ((ans == INT_MIN) ? 0 : ans);
    }
};