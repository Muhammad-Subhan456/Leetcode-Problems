class Solution {
public:

void dfs(int i, int j,vector<vector<int>>&vis,vector<vector<int>>& grid, int&cnt){
    int n = grid.size();
    int m = grid[0].size(); 
    if(i < 0 || j < 0){
        cnt++;
        return;
    }
    if(i >= n || j >= m){
        cnt++;
        return;
    } 
    if(grid[i][j] == 0){
        cnt++;
        return;
    }
    if(vis[i][j]) return;
    vis[i][j] = 1;
    dfs(i-1,j,vis,grid,cnt);
    dfs(i+1,j,vis,grid,cnt);
    dfs(i,j-1,vis,grid,cnt);
    dfs(i,j+1,vis,grid,cnt);
}

    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int r=0; r < n; ++r){
            for(int c=0; c < m; ++c){
                if(!vis[r][c] && grid[r][c] == 1){
                    dfs(r,c,vis,grid,cnt);
                }
            }
        }
        return cnt;
    }
};