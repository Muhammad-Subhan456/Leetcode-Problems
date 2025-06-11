class Solution {
public:

bool dfs(int i, int j,vector<vector<char>>& board, string s, int idx ){
    int n = board.size();
    int m = board[0].size(); 
    if(idx == s.size()) return true;
    if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != s[idx] ){
        return false;
    }
    char temp = board[i][j];
    board[i][j] = '#';

    bool found =dfs(i + 1, j, board,s, idx + 1) ||
                dfs(i - 1, j, board,s, idx + 1) ||
                dfs(i, j + 1, board,s, idx + 1) ||
                dfs(i, j - 1, board,s, idx + 1);
   
    board[i][j] = temp;
    return found;
}


    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (board[r][c] == word[0]) {
                    if (dfs(r, c, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
    
};