class Solution {
public:
    int dp[100];
    int rec(int level,int n){
        if(level > n) return 0;
        if(level==n) return 1;
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans=0;
        for(int step=1; step <=2; step++){
            if(level+step<=n){
               int ways = rec(level+step,n);
               ans += ways;
            }
        }
        dp[level] = ans;
        return ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n);
    }
};