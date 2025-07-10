class Solution {
public:
int rec(int i,int buy,vector<int>&a,int n,vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    int profit = 0;
    if(buy){
        profit = max(-a[i]+rec(i+1,0,a,n,dp),0+rec(i+1,1,a,n,dp));
    }
    else{
        profit = max(a[i]+rec(i+1,1,a,n,dp),0+rec(i+1,0,a,n,dp));

    }
    return dp[i][buy] = profit;
    
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return rec(0,1,prices,prices.size(),dp);
        
    }
};