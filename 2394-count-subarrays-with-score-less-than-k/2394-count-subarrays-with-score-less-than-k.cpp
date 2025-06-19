class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long l = 0, r = 0, sum = 0, cnt = 0;
        int n = nums.size();
        
        while (r < n) {
            sum += nums[r];
            while (sum * (r - l + 1) >= k) {
                sum -= nums[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        
        return cnt;
    }
};
