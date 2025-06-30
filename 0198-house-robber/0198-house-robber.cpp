class Solution {
public:
    int rec(int ind,vector<int>&n,vector<int>&dp){
        if(ind==0) return n[ind];
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = n[ind] + rec(ind-2,n,dp);
        int notpick = rec(ind-1,n,dp);
        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(1e3,-1);
        return rec(n-1,nums,dp);
    }
};