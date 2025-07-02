class Solution {
public:
    int rec(int i, int j,vector<vector<int>>&tri,vector<vector<int>>&dp,int n){
        if(i==n-1) return tri[n-1][j];
        //if(i >= n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = tri[i][j] + rec(i+1,j,tri,dp,n);
        int dia = tri[i][j] + rec(i+1,j+1,tri,dp,n);
        return  dp[i][j] = min(down,dia);
    }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     int m =triangle[n-1].size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return rec(0,0,triangle,dp,n);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m =triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0; j < m; ++j)
             dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2; i >= 0; --i){
            for(int j=i; j >=0; --j){
                int down = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,dia);
            }
        }
        return dp[0][0];
        
    }
};