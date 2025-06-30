class Solution {
public:
    set<vector<int>> ans;
     void print(int ind, vector<int>& ds, vector<int>& nums, int n) {
        if (ind == n) {
            ans.insert(ds);
            return;
        }
        // take it
        ds.push_back(nums[ind]);
        print(ind + 1, ds, nums, n);
        ds.pop_back(); // backtrack
        // don't take it
        print(ind + 1, ds, nums, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        print(0, ds, nums, nums.size());
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
