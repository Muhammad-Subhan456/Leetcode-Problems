class Solution {
public:
    string clearStars(string s) {
        auto cmp = [](const pair<char,int>& a, const pair<char,int>& b) {
            if (a.first == b.first)
                return a.second < b.second;  
            return a.first > b.first;        
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp);

        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                auto p = pq.top(); pq.pop();
                s[p.second] = '.';  
                s[i] = '.';     
            }
        }

        string t = "";
        for (char c : s) {
            if (c != '.')
                t += c;
        }

        return t;
    }
};
