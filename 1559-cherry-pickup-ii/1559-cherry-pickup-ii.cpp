class Solution {
public:
int rec(int i,int j1,int j2,int r,int c,vector<vector<int>>&a,  vector<vector<vector<int>>>&dp){
    if(j1<0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;
    if(i==r-1){
        if(j1==j2) return a[i][j1];
        else return a[i][j1]+a[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    //explore all paths simultaneouly
    int maxi = -1e8;
    for(int dj1 = -1; dj1<=1; dj1++){
        for(int dj2=-1; dj2 <= 1; dj2++){
            int value = 0;
            if(j1==j2) value = a[i][j1];
            else value = a[i][j1] + a[i][j2];
            value += rec(i+1,j1+dj1,j2+dj2,r,c,a,dp);
            maxi = max(maxi,value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return rec(0,0,c-1,r,c,grid,dp);
    }
        
};