class Solution {
public:
    const int MOD  = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2,-1)));
        function <int(int,int,bool)> dfs = [&](int i,int j, bool isR) -> int{
            if(i>=m || j >= n) return 0;
            if(i==m-1 && j==n-1) return 1;
            if(dp[i][j][isR] != -1) return dp[i][j][isR];
            int ans=0;
            if(grid[i][j]){
                if(isR){
                    ans += dfs(i+1,j,false)%MOD;
                }
                else{
                    ans += dfs(i,j+1,true)%MOD;
                }
            }
            else{
                ans = (dfs(i+1,j,false)+dfs(i,j+1,true))%MOD;
            }
            return dp[i][j][isR] = ans;
        };
        return dfs(0,0,false);
    }
};