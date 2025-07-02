class Solution {
public:
    int rec(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0) return grid[0][0];
        if(i < 0 || j < 0 ) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + rec(i-1,j,grid,dp);
        int left = grid[i][j] + rec(i,j-1,grid,dp);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return rec(i-1,j-1,grid,dp);
    }
};