class Solution {
public:

int rec(int i,int prevInd,int n,vector<int>&a,vector<vector<int>>&dp){
    if(i == n) return 0;
    if(dp[i][prevInd+1] != -1) return dp[i][prevInd+1];
    int len = 0;
    // Not Take
    len = 0 + rec(i+1,prevInd,n,a,dp);
    // Take
    if(prevInd==-1 || a[i] > a[prevInd])
        len = max(len,1 + rec(i+1,i,n,a,dp));
    return dp[i][prevInd+1] = len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return rec(0,-1,n,nums,dp);
    }
};