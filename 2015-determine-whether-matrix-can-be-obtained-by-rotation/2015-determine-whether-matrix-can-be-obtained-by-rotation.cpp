class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for(int i=0; i<4;++i){
        for(int j=0; j < mat.size();++j){
            for(int k=0;k<j;k++){
                swap(mat[j][k],mat[k][j]);
            }
        }
        for(int i=0; i < mat.size();++i){
            reverse(mat[i].begin(),mat[i].end());
        }
        if(mat==target)
            return true;
    }   
    return false;
    }
};