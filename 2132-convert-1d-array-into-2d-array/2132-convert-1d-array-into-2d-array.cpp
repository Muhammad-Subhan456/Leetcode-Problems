class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(n*m!=original.size()) return {};
    vector<vector<int>>mat(m,vector<int>(n));
    int k=0;
    
    for(int i=0; i<m;++i){
        for(int j=0; j<n;++j){
            mat[i][j]=original[k++];
        }
    }
    return mat;
    }
};