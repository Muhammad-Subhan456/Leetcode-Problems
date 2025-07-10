class Solution {
public:
int rec(int i,int buy,int n,vector<int>&a,vector<vector<int>>&dp){
    if(i>=n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    int profit=0;
    if(buy){
        profit= max(-a[i]+rec(i+1,0,n,a,dp),0+rec(i+1,1,n,a,dp));
    }
    else{
        profit=max(a[i]+rec(i+2,1,n,a,dp),0+rec(i+1,0,n,a,dp));
    }
    return dp[i][buy] = profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    return rec(0,1,n,prices,dp);
        
    }
};