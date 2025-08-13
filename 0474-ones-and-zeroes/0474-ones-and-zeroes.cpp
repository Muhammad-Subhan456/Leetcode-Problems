class Solution {
public:
int rec(int i,int m,int n,vector<string>& strs,vector<vector<vector<int>>>&dp){
    if(i==0){
    string s = strs[i];
    int zeros = count(s.begin(),s.end(),'0');
    int ones = count(s.begin(),s.end(),'1');
    if(zeros <= m && ones <= n) return 1;
    return 0;
    }
    if(dp[i][m][n] != -1) return dp[i][m][n];

    int notake = rec(i-1,m,n,strs,dp);
    int take=0;
    string s = strs[i];
    int zeros = count(s.begin(),s.end(),'0');
    int ones = count(s.begin(),s.end(),'1');
    if(zeros <= m && ones <= n){
        take = 1 + rec(i-1,m-zeros,n-ones,strs,dp);
    }
    return dp[i][m][n] = max(notake,take);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
vector<vector<vector<int>>>dp(size+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return rec(size-1,m,n,strs,dp);
    }
};