class Solution {
public:
int rec(int ind,int k,vector<int>&coins,vector<vector<int>>&dp){
    if(ind==0){
        if(k % coins[ind]==0) return  k/coins[ind];
        return 1e9;
    }
    if(dp[ind][k] != -1) return dp[ind][k];
    int nottake = 0 + rec(ind-1,k,coins,dp);
    int take = INT_MAX;
    if(coins[ind]<=k)
    take = 1 + rec(ind,k-coins[ind],coins,dp);
    return dp[ind][k] = min(take,nottake);
}

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = rec(n-1,amount,coins,dp);
        return ans < 1e9 ? ans : -1;
    }
};