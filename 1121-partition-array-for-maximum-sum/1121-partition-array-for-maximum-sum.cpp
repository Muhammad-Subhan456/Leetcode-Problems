class Solution {
public:
int rec(int i,int k,vector<int>&a,int n,vector<int>&dp){
    if(i==n) return 0;
    if(dp[i] !=-1) return dp[i];
    int maxAns = INT_MIN, maxi = INT_MIN, len=0;
    for(int j=i;j < min(n,i+k);++j){
        len++;
        maxi = max(maxi,a[j]);
        int sum = len * maxi + rec(j+1,k,a,n,dp);
        maxAns = max(maxAns,sum);
    }
    return dp[i] = maxAns;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return rec(0,k,arr,n,dp);
    }
};