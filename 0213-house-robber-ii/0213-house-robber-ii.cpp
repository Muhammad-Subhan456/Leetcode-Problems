class Solution {
public:
    int rec(int ind,vector<int>&n,vector<int>&dp){
        if(ind==0) return n[ind];
        if(ind==1) return max(n[0],n[1]);
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = n[ind] + rec(ind-2,n,dp);
        int notpick = rec(ind-1,n,dp);
        return dp[ind] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp1(n+1,-1), dp2(n+1,-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        return max(rec(n-2,nums,dp1),rec(n-2,nums2,dp2));
    }
};