class Solution {
public:

    int rec(int k,vector<int>& nums,vector<int>&dp){
        if(k==0) return 1;
        if(dp[k]!=-1) return dp[k];
        int ways=0;
        for(int n: nums){
            if(n <= k){
                ways += rec(k-n,nums,dp);
            }
        }
        return dp[k] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return rec(target,nums,dp);
    }
};