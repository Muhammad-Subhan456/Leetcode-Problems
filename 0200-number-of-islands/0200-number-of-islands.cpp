class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>&vis,vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 || j < 0) return;
    if(i >= n || j >= m) return;
    if(grid[i][j] != '1') return;
    if(vis[i][j]) return;
    vis[i][j] = 1;
    dfs(i-1,j,vis,grid);
    dfs(i+1,j,vis,grid);
    dfs(i,j-1,vis,grid);
    dfs(i,j+1,vis,grid);
}

    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       int cnt=0;
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int r=0; r < n; r++){
            for(int c=0; c < m; ++c){
                if(!vis[r][c] && grid[r][c]=='1'){
                    cnt++;
                    dfs(r,c,vis,grid);
                }
            }
       } 
       return cnt;
    }
};