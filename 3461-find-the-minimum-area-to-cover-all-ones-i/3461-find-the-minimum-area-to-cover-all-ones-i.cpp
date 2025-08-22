class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0,mini=1e4,maxi=-1e4;
        int minir = 1e4, maxir = -1e4;
        for(int i=0; i < n; ++i){
            for(int j=0; j < m; ++j){
                if(grid[i][j]==1){
                    mini = min(mini,j);
                    maxi = max(maxi,j);
                    minir = min(minir,i);
                    maxir = max(maxir,i);
                }
            }
        }
        cout << maxi << " " << mini << " " << cnt;
        return (maxi-mini+1)*(maxir-minir+1);

    }
};