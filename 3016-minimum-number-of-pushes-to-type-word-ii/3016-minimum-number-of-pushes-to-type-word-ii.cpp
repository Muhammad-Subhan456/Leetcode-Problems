class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto &c : word) mp[c]++;
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](const auto &a, const auto &b){
            return a.second > b.second;
        });
        int n = v.size(),cnt=0;
        for(int i=0; i < n; ++i)
            cnt += (mp[v[i].first]* ((i/8)+1));
        
        return cnt;
    }
};