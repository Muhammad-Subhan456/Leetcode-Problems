class Solution {
public:
    using ll = long long;
    long long rec(long long i,long long j,long long s,vector<vector<int>>&wc,
    vector<vector<vector<ll>>>&dp){
        if(i < 0 || j < 0 ) return 1e18;
        if(i==0 && j==0) return 0;
        if(dp[i][j][s] != -1) return dp[i][j][s];
        long long up = LLONG_MAX, left = LLONG_MAX, ans=0;
        if(s&1){
         up =  ((i+1)*(j+1)) + rec(i-1,j,0,wc,dp);
        left =  ((i+1)*(j+1)) + rec(i,j-1,0,wc,dp);
        ans = min(up,left);
        }
        else
        ans = (wc[i][j]+rec(i,j,1,wc,dp));
        return dp[i][j][s] = ans;
    }

        
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
    vector<vector<vector<ll>>> dp(m, vector<vector<ll>> (n, vector<ll> (2, -1)));
        return 1+rec(m-1,n-1,1,waitCost,dp);
    }
};