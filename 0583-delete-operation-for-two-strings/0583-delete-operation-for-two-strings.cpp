class Solution {
public:
int rec(int i,int j,string &s, string &t,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i]==t[j]) 
    return 1+ rec(i-1,j-1,s,t,dp);
    return dp[i][j]= max(rec(i-1,j,s,t,dp),rec(i,j-1,s,t,dp));
}
    int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int a = rec(n-1,m-1,word1,word2,dp);
    return ((n-a)+(m-a));

    }
};