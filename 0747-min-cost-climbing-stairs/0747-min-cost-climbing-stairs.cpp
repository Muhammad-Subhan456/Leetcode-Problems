class Solution {
public:
    int rec(int i,vector<int>&c,vector<int>&dp){
        if(i==0) return c[i];
        if(i==1) return c[i];
        if(i < 0) return 0;
        if(dp[i]!=-1) return dp[i];
        int fs = c[i] + rec(i-1,c,dp);
        int ss = c[i] + rec(i-2,c,dp);
        return dp[i]=min(fs,ss);
    }
    int minCostClimbingStairs(vector<int>& c) {
        int n = c.size();
        vector<int>dp(n,-1);
        dp[0] = c[0];
        dp[1] = c[1];
        for(int i=2; i < n; ++i){
            int fs = c[i] + dp[i-1];
            int ss = c[i] + dp[i-2];
            dp[i] = min(fs,ss);
        }
        return min(dp[n-1],dp[n-2]);
    }
};