class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        string t = "";
        for(auto &c : s) m[c]++;
        for(auto &c : order){
            if(m[c]){
                t.append(m[c],c);
                m.erase(c);
            }
        }
        for(auto &p : m){
            t.append(p.second,p.first);
        }
        return t;
    }
};