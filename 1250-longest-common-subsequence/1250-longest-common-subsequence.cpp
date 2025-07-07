class Solution {
public:
int rec(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    // case when character match
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i]==s2[j])
        return  dp[i][j] = 1 + rec(i-1,j-1,s1,s2,dp);
    // case when characters doesnt match
    return dp[i][j] = 0 + max(rec(i-1,j,s1,s2,dp),rec(i,j-1,s1,s2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int i= text1.length();
        int j = text2.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return rec(i-1,j-1,text1,text2,dp);
    }
};