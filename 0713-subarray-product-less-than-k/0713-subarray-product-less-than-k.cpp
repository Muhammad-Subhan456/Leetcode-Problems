class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        long long l = 0, r = 0, cnt = 0, pro = 1, n = nums.size();
        
        while(r < n){
            pro *= nums[r];
            while(pro >= k){
                pro /= nums[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        
        return cnt;
    }
};
