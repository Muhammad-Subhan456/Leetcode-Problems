class Solution {
public:
int rec(int i,int buy,vector<int>&a,int n,int cap,vector<vector<vector<int>>>&dp){
    if(cap==0) return 0;
    if(i==n) return 0;
    if(dp[i][buy][cap] !=-1) return dp[i][buy][cap];
    int profit = 0;
    if(buy){
    profit = max(-a[i]+rec(i+1,0,a,n,cap,dp),
                            0+rec(i+1,1,a,n,cap,dp));
    }
    else
    {
        profit = max(a[i]+rec(i+1,1,a,n,cap-1,dp),
        0 + rec(i+1,0,a,n,cap,dp));
    }
    return dp[i][buy][cap] = profit;
    
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return rec(0,1,prices,n,2,dp);
        
    }
};