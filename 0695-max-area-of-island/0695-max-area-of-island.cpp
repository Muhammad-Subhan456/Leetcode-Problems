class Solution {
public:
    int bfs(int r, int c, vector<vector<int>>&vis,vector<vector<int>>&grid){
        int cnt=0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vis[r][c] = 1;
        q.push({r,c});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // 4 directions
            for(int i=0; i < 4; ++i){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

            if(nrow>=0 && nrow < n && ncol >=0 && ncol < m &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
                cnt++;
                }

            }
        }
        return cnt+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int r=0; r < n; ++r){
            for(int c=0; c < m; ++c){
                if(!vis[r][c] && grid[r][c]==1){
                    maxi = max(bfs(r,c,vis,grid),maxi);
                }
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};