class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.resize(n);
        suffix[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = piles[i] + suffix[i+1];
        }
        dp.assign(n,vector<int>(n+1,-1));

        function<int(int,int)> solve = [&](int i, int m)-> int{
            if(i >= n) return 0;
            if(dp[i][m] != -1) return dp[i][m];
            if(i + 2*m >= n) return dp[i][m] = suffix[i];
            int ans = 0;
            for(int x = 1; x <= 2*m; x++){
                int oppo = solve(i+x,max(m,x));
                int current = suffix[i] - oppo;
                ans = max(ans,current);
            }
            return dp[i][m] = ans;
        };
        return solve(0,1);
    }
};