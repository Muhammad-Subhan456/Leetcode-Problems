class Solution {
public:
void bfs(int r, int c,vector<vector<int>>&vis,vector<vector<char>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    vis[r][c] = 1;
    q.push({r,c});

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        grid[row][col] = '#';
        // for 4 directions;
        for(int i=0; i < 4; ++i){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow < n && ncol >=0 && ncol < m
            && !vis[nrow][ncol] && grid[nrow][ncol]=='O'){
               vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
        
    }

}

    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i < n; ++i){
            if(grid[i][0] == 'O' && !vis[i][0]) bfs(i,0,vis,grid);
            if(grid[i][m-1] == 'O' && !vis[i][m-1]) bfs(i,m-1,vis,grid);
        }
        for(int j=0; j < m; ++j){
            if(grid[0][j]=='O' && !vis[0][j]) bfs(0,j,vis,grid);
            if(grid[n-1][j]=='O' && !vis[n-1][j]) bfs(n-1,j,vis,grid);
        }

        for(int i=0; i < n; ++i){
            for(int j=0; j < m; ++j){
                if(grid[i][j]=='O') grid[i][j] = 'X';
                else if(grid[i][j]=='#') grid[i][j] = 'O';
            }
        }
    }
};