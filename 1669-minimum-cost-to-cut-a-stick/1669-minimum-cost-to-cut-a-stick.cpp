class Solution {
public:
int rec(int i,int j,vector<int>&c,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for(int ind=i; ind <=j; ind++){
        int cost = c[j+1]-c[i-1] + rec(i,ind-1,c,dp)+rec(ind+1,j,c,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}
    int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());   
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return rec(1,c,cuts,dp);
    }
};