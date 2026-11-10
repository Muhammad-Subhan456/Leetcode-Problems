class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int cost = 0;
        vector<int>dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int i = n-1; i>=0;--i){
            for(int jump=1; jump <= 3; ++jump){
                int j = i + jump;
                if(j <= n){
                    int c = costs[j-1] + jump*jump;
                    dp[i] = min(dp[i],c + dp[j]);
                }
            }
        }
        return dp[0];
        
    }
};