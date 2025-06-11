class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;

        for(int i=0; i < n; ++i){
            for(int j=0; j < m; ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int mins = -1;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int size = q.size();
            mins++;
            for(int i=0; i < size; ++i){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0; i < 4; ++i){
                    int nrow = x + drow[i];
                    int ncol = y + dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow < n && ncol < m
                    && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                        fresh--;
                    }
                }   
            }
        }
        return fresh==0 ? mins : -1;
    }
};