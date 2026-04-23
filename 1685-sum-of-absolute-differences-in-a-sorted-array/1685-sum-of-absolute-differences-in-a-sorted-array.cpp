class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        for(auto c : nums) sum += c;
        int n = nums.size();
        vector<int>ans(n);
        int lsum = 0;
        for(int i=0; i < n; ++i){
            int rsum = sum - lsum - nums[i];
            ans[i] = (i*nums[i]-lsum) + (rsum-(n-i-1)*nums[i]);
            lsum += nums[i];
        }
        return ans;
    }
};