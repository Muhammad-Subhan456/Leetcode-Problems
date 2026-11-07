class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [&](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<vector<int>> query;
        int q = queries.size();

        for(int i = 0; i < q; ++i)
            query.push_back({i, queries[i]});

        sort(query.begin(), query.end(), [&](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> res(q, 0);
        int l = 0, r = 0;
        map<int,int> mp;
        for(int i = 0; i < q; ++i) {
            int curr = query[i][1];
            while(r < logs.size() && logs[r][1] <= curr) {
                mp[logs[r][0]]++;
                r++;
            }
            while(l < r && logs[l][1] < curr - x) {
                mp[logs[l][0]]--;

                if(mp[logs[l][0]] == 0)
                    mp.erase(logs[l][0]);

                l++;
            }

            int idx = query[i][0];
            res[idx] = n - mp.size();
        }

        return res;
    }
};