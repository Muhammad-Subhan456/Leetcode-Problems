class Solution {
public:
     vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& heights,int i, int j,int prev, vector<vector<int>>&ocean){
        int row = heights.size(), col = heights[0].size();
        if(i < 0 || i >= row || j < 0 || j >= col) return;
        if(heights[i][j] < prev || ocean[i][j]) return;
        ocean[i][j] = 1;
        for(auto d : dir){
            dfs(heights,i+d[0],j+d[1],heights[i][j],ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if(heights.size()==0 || heights[0].size()==0) return res;
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> pacific(row,vector<int>(col,0));
        vector<vector<int>> atlantic(row,vector<int>(col,0));
        for(int i=0; i < col; ++i){
            dfs(heights,0,i,INT_MIN,pacific);
            dfs(heights,row-1,i,INT_MIN,atlantic);
        }
        for(int i=0; i < row; ++i){
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,col-1,INT_MIN,atlantic);
        }

        for(int i=0; i < row; ++i){
            for(int j=0; j < col; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};