class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long modPow(long long a, long long e) {
        long long res = 1;
        a %= MOD;
        while (e) {
            if (e & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }
    vector<int> bin(int n) {
        vector<int> p;
        long long cur = 1;
        while (n > 0) {
            if (n & 1) p.push_back((int)cur);
            cur = (cur * 2) % MOD;
            n >>= 1;
        }
        sort(p.begin(), p.end()); 
        int m = p.size();
        vector<int> pre(m);
        if (m) {
            pre[0] = p[0] % MOD;
            for (int i = 1; i < m; ++i)
                pre[i] = (int)((1LL * pre[i - 1] * p[i]) % MOD);
        }
        return pre;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> pro = bin(n); 
        for (auto &qr : queries) {
            int l = qr[0], r = qr[1];
            if (l == 0) {
                ans.push_back(pro[r]);
            } else {
                long long denom = pro[l - 1];
                long long inv = modPow(denom, MOD - 2); 
                ans.push_back((int)((pro[r] * inv) % MOD));
            }
        }
        return ans;
    }
};
