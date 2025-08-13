class Solution {
public:
using ll = long long;
ll rec(int i,int n,vector<vector<int>>&q,vector<ll>&dp ) {
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    ll take = q[i][0]+ rec(i+q[i][1]+1,n,q,dp);
    ll no = rec(i+1,n,q,dp);
    return dp[i] = max(take,no);
}

    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll>dp(n+1,-1);
        return rec(0,n,questions,dp);
    }
};