class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i < n; ++i){
            int t = 0;
            for(int j=i; j < n; ++j){
                if(nums[j] == target) t++;
                if(2*t > (j-i+1)) cnt++;
            }
        }
        return cnt;
    }
};