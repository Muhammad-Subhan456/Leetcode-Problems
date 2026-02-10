class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size(),temp=0;
        vector<int>o(n);
        for(int i=0; i < n; ++i){
            int idx = (i + nums[i] % n + n) % n;
            o[i] = nums[idx];
        }
        return o;       
    }
};