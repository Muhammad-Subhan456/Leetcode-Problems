class Solution {
public:
bool is(int l,int r,string &s){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;r--;
    }
    return true;
}
int rec(int i,int n,string&s,vector<int>&dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mini = INT_MAX;
    for(int j=i; j < n; ++j){
        if(is(i,j,s)){
            int cost = 1 + rec(j+1,n,s,dp);
            mini = min(cost,mini);
        }
    }
    return dp[i]=mini;
}
    int minCut(string s) {
        vector<int>dp(s.size()+1,-1);
        return rec(0,s.size(),s,dp)-1;
    }
};