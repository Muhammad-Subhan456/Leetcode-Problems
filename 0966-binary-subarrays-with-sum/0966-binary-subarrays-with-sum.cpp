class Solution {
public:
    int countSubarrays(vector<int>& nums, int goal){
        if(goal < 0 ) return 0;
       int l=0,r=0,cnt=0, n = nums.size(),sum=0;

        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum-= nums[l++];
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int x = countSubarrays(nums,goal);
        int y = countSubarrays(nums,goal-1);
        return x-y;
        
    }
};