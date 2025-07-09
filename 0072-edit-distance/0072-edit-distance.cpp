class Solution {
public:
int rec(int i,int j,string& s,string& t,vector<vector<int>>&dp){
    if(i < 0) return j+1; // we need to add j+1 characters in s1
    if(j < 0) return i+1; // we need to delete i+1 chars in s1
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j] = 0 + rec(i-1,j-1,s,t,dp); //character found so we dont need to perform any operation return 0
    int op1 = 1+rec(i,j-1,s,t,dp); // insert operation
    int op2 = 1+rec(i-1,j,s,t,dp); //delete operation
    int op3 = 1+rec(i-1,j-1,s,t,dp); //replace operation
    return dp[i][j] = min({op1,op2,op3});
    }
    
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return rec(n-1,m-1,s,t,dp);
    }
};