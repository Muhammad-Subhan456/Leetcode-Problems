class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    vis[r][c] = 1;
    q.push({r, c});

    int drow[] = {-1, 0, 1, 0}; // up, right, down, left
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
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
                    bfs(r,c,vis,grid);
                }
            }
       } 
       return cnt;
    }
};