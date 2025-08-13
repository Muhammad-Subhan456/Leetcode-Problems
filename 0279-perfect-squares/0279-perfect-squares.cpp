class Solution {
public:
int rec(int i,int n,vector<int>&p,vector<vector<int>>&dp){
    if(i==0){
        if(n % p[i]==0) return n/p[i];
        return 1e9;
    }
    if(dp[i][n] != -1) return dp[i][n];
    int notake = rec(i-1,n,p,dp);
    int take = INT_MAX;
    if(p[i] <= n){
        take = 1+ rec(i,n-p[i],p,dp);
    }
    return dp[i][n] = min(notake,take);
}

    int numSquares(int n) {
        int s = 100;
        vector<int>perfect(s);
        for(int i=1; i<=100; ++i) perfect[i-1]= i*i;
        vector<vector<int>>dp(s+1,vector<int>(n+1,-1));
        return rec(s-1,n,perfect,dp);
    }
};