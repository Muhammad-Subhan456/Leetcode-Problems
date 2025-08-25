class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        for (int d = 0; d < n + m - 1; d++) {
            vector<int> res;
            int r = (d < m ? 0 : d - m + 1);
            int c = (d < m ? d : m - 1);
            while (r < n && c >= 0) {
                res.push_back(mat[r][c]);
                r++;
                c--;
            }
            if (d % 2 == 0) {
                reverse(res.begin(), res.end());
            }
            ans.insert(ans.end(), res.begin(), res.end());
        }
        return ans;
    }
};
