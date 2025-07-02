class Solution {
public:
int rec(int i,int j,int m,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(j < 0 || j >= m ) return 1e9;
    if(i==0) return mat[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int str = mat[i][j] + rec(i-1,j,m,mat,dp);
    int left = mat[i][j] + rec(i-1,j-1,m,mat,dp);
    int right = mat[i][j] + rec(i-1,j+1,m,mat,dp);
    return dp[i][j] = min({str,left,right});
} 
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp = matrix;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = dp[i-1][j];
                int left = (j > 0) ? dp[i-1][j-1] : 1e9;
                int right = (j < n-1) ? dp[i-1][j+1] : 1e9;
                dp[i][j] += min({up, left, right});
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};