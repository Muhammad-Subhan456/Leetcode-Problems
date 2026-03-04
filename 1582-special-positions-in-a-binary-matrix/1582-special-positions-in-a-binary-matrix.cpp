class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        for(int i=0; i < n; ++i){
            for(int j=0; j < m; ++j){
                // sum
                if(mat[i][j]==1){

                int sum=0;
                for(int k = 0; k < m; ++k) sum += mat[i][k];
                for(int l = 0; l < n; ++l) sum += mat[l][j];
              //  cout << sum << '\n';
                cout << mat[i][j] << ',' << sum << ' ';
                if(sum == 2 ) cnt++;
                }
            }
            cout << '\n';
        }
        return cnt;
    }
};