class NumMatrix {
    vector<vector<int>> pre; 
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        int m = n ? (int)mat[0].size() : 0;

        pre.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pre[i][j] = mat[i-1][j-1]
                            + pre[i-1][j]
                            + pre[i][j-1]
                            - pre[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) {
       
        return pre[c + 1][d + 1]
             - pre[a][d + 1]
             - pre[c + 1][b]
             + pre[a][b];
    }
};
