class Solution {
public:
    void find(int i, vector<int>& candidates, int t, vector<vector<int>>& ans, vector<int>& ds) {
        if (i == candidates.size()) {
            if (t == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[i] <= t) {
            ds.push_back(candidates[i]);
            find(i, candidates, t - candidates[i], ans, ds);
            ds.pop_back();
        }
        find(i + 1, candidates, t, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(0, candidates, target, ans, ds);
        return ans;
    }
};
