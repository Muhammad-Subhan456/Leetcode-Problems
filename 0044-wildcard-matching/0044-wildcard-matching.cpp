class Solution {
public:
int rec(int i,int j,string&s,string&t,vector<vector<int>>&dp){
    //both strings exhausted means they are equal return true
    // s1 = "" == s2 = ""
    if(i<0 && j<0) return true;
    // if s1 exhausted and s2 still remains which means chars cant match
    //e.g: s1="" and s2= "abc"
    if(i<0 && j>=0) return false;
    //if s2 exhausted for example
    // s1 = "***" s2 = "" then each star can be mapped with empty subsq
    // so we will check if any char is not * than return false
    if(j<0 && i>=0){
        for(int j=0;j<=i;++j){
            if(s[j]!= '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
//if char is equal to char or ? then move both strings indices
    if(s[i]==t[j] || s[i]=='?') 
    return dp[i][j] = rec(i-1,j-1,s,t,dp);
    else if(s[i]=='*')
// rec(i-1,j,s,t,dp)-> treat * as empty subsq and move
// rec(i,j-1,s,t,dp)-> map char with * until equal chars find
// for clarity refer to notes
    return dp[i][j]= rec(i-1,j,s,t,dp) || rec(i,j-1,s,t,dp);
// this returns false meaning i and j chars doesnt match
    return dp[i][j] = false;
}
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return rec(n-1,m-1,p,s,dp);
    }
};