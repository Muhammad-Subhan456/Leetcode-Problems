class Solution {
public:
    bool rec(int ind,int k,vector<int>&a,vector<vector<int>>&dp){
        if(k==0) return true;
        if(ind==0) return (a[0]==k);
        if(dp[ind][k] != -1) return dp[ind][k];
        bool notTake = rec(ind-1,k,a,dp);
        bool take = false;
        if(a[ind] <= k){
            take = rec(ind-1,k-a[ind],a,dp);
        }
        return dp[ind][k] = (take||notTake);
    }
    bool canPartition(vector<int>& nums){
        int sum = 0;
        for(auto c : nums) sum += c;
        if(sum&1) return false;
        else{
            int n = nums.size();
            int m = sum/2;
            vector<vector<int>>dp(n,vector<int>(m+1,-1));
            return rec(n-1,m,nums,dp);
        }

    }
};