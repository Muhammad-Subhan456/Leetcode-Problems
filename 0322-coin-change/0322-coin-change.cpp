class Solution {
public:
    using vii = vector<vector<int>>;
    using vi = vector<int>;
    int coinChange(vector<int>& a, int k) {
        int n = a.size();
        vii dp(n, vi(k + 1,-1));
    function<int(int, int)> rec = [&](int i, int k) -> int
    {
        if(i == 0){
            if(k % a[i] == 0) return k/a[i];
            return 1e9;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int nt = 0 + rec(i-1,k);
        int t = 1e9;
        if(a[i] <= k){
            t = 1 + rec(i,k-a[i]);
        }
        return dp[i][k] = min(t,nt);
    };
    int ans = rec(n-1,k);
    return ans < 1e9 ?  ans :  -1;
    }
};