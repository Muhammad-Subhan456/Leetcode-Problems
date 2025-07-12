class Solution {
public:
bool checkPossible(string &s1,string &s2){
    if(s1.size() != s2.size()+1) return false;
    int first = 0, second = 0;
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first++;
            second++;
        }
        else first++;
    }
    if(first==s1.size() && second == s2.size()) return true;
    return false;
}
int rec(int i,int prevInd,int n,vector<string>&a,vector<vector<int>>&dp){
    if(i == n) return 0;
    if(dp[i][prevInd+1] != -1) return dp[i][prevInd+1];
    int len = 0;
    // Not Take
    // if not taking so len will be zero we will move to next index and previous index remains same
    len = 0 + rec(i+1,prevInd,n,a,dp);
    // Take
    
    if(prevInd==-1 || checkPossible(a[i],a[prevInd]))
    // if taking len will inc by one ind will increase and prev index will become current ind
        len = max(len,1 + rec(i+1,i,n,a,dp));
    return dp[i][prevInd+1] = len;
}
static bool cmp(string &s1, string &s2){
    return s1.size() < s2.size();
} 
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
       // int m = words[n-1].size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(0,-1,n,words,dp);
    }
};