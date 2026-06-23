class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;
        r -= l;

        vector<vector<int>> dp(n, vector<int>(r + 1, 0));

        for (int j = 0; j <= r; ++j)
            dp[0][j] = 1;

        for (int i = 1; i < n; ++i) {
            int prev = 0;

            if (i & 1) {
                for (int j = 0; j <= r; ++j) {
                    dp[i][j] = prev;
                    prev = (prev + dp[i - 1][j]) % mod;
                }
            } else {
                for (int j = r; j >= 0; --j) {
                    dp[i][j] = prev;
                    prev = (prev + dp[i - 1][j]) % mod;
                }
            }
        }

        int ans = 0;
        for (int j = 0; j <= r; ++j)
            ans = (ans + dp[n - 1][j]) % mod;

        return (ans * 2LL) % mod;
    }
};