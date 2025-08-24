class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,del=0,s=0;
        int n = nums.size();
        while(r < n){
            if(nums[r]==0) del++;
            while(del > 1){
                if(nums[l]==0) del--;
                l++;
            }
            s = max(s,r-l+1);
            r++;
        }
        return s-1;
    }
};