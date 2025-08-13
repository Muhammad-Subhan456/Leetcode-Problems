class Solution {
public:
int rec(int i,int n,vector<int>& days, vector<int>& costs,vector<int>&dp){
    if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int one = costs[0] + rec(i+1,n,days,costs,dp);
         auto it   = lower_bound(days.begin(), days.end(), days[i] + 7);
        int seven = costs[1] + rec(it - days.begin(), n, days, costs, dp);

        it        = lower_bound(days.begin(), days.end(), days[i] + 30);
        int thr   = costs[2] + rec(it - days.begin(), n, days, costs, dp);
    
    return dp[i] = min({one,seven,thr});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);
        return rec(0,days.size(),days,costs,dp);
    }
};