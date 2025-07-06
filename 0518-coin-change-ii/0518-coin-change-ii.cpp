class Solution {
public:
using ull = unsigned long long;
int rec(int ind,int k,vector<int>&coins,vector<vector<ull>>&dp){
    if(ind==0){
        if(k % coins[ind]==0) return 1;
        return 0;
    }
    if(dp[ind][k] != -1) return dp[ind][k];
    int nottake = rec(ind-1,k,coins,dp);
    int take = 0;
    if(coins[ind]<=k)
    take = rec(ind,k-coins[ind],coins,dp);
    return dp[ind][k] = (nottake+take);
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ull>>dp(n+1,vector<ull>(amount+1,-1));
        int ans = rec(n-1,amount,coins,dp);
        return ans;
        
    }
};