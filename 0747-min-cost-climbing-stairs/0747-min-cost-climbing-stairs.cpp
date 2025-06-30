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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(rec(n-1,cost,dp) , rec(n-2,cost,dp));
    }
};