class Solution {
public:
    int rec(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i < 0 || j < 0 ) return 0;
        if(grid[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = rec(i-1,j,grid,dp);
        int left = rec(i,j-1,grid,dp);
        return dp[i][j] = (up+left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0]==1) return 0;
     int n = obstacleGrid.size();
     int m = obstacleGrid[0].size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
     return rec(n-1,m-1,obstacleGrid,dp);
    }
};