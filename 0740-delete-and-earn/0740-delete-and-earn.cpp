class Solution {
public:
int rec(int i,vector<int>&a,map<int,int>&mp,vector<int>&dp){
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];
    int take = a[i]*mp[a[i]];
    if(i>0 && (a[i] == a[i-1]+1)){
        take += rec(i-2,a,mp,dp);
    }
    else{
        take += rec(i-1,a,mp,dp);
    }
    int skip = rec(i-1,a,mp,dp);
    return dp[i] = max(take,skip);

}
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;int i=0;
        for(auto &c : nums) mp[c]++;
        vector<int>a(mp.size());
        for(auto p : mp) a[i++] = p.first;
        int n = a.size();
        vector<int>dp(n,-1);
        return rec(n-1,a,mp,dp);
    }
};