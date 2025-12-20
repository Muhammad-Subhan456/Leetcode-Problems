class Solution {
public:
    
    bool canJump(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n+1,-1);
       function<bool(int)> rec = [&](int ind)-> bool{
            if(ind >= n) return false;
            if(ind == n-1) return true;
            if(dp[ind] != -1) return dp[ind];
            for(int i=1; i <= nums[ind]; i++){
                if(rec(ind+i))
                    return dp[ind] = true;
            }
            return dp[ind] = false;
       };
       return rec(0);
    }
};