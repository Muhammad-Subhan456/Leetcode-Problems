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
    vector<int>temp;
    temp.push_back(nums[0]);
    for(int i=1; i < nums.size(); ++i){
        if(nums[i] > temp.back()) temp.push_back(nums[i]);
        else{
        int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        temp[ind] = nums[i];
        }
    }
    return temp.size();
    }
};