class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int,int>m;
    vector<vector<int>>ans;
    for(int i=0; i < nums1.size();++i){
        m[nums1[i][0]] = nums1[i][1];
    }
    for(int i=0; i < nums2.size();++i){
        m[nums2[i][0]] += nums2[i][1];
    }

    for(auto pair : m){
        vector<int>nums;
        nums.push_back(pair.first);
        nums.push_back(pair.second);
        ans.push_back(nums);
    }
    return ans;
    }
};