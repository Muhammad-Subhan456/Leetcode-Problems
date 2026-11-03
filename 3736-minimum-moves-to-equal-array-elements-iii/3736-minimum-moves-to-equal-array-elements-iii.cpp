class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int cnt = 0;
        for(auto &c : nums) cnt += (maxi-c);
        return cnt;
    }
};