class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        string t;
        if(k > n) return false;
        for(int i=0; i < k; ++i) t += s[i];
        int r = k-1;
        set<string>st;
        while(r < n){
            st.insert(t);
            if(!t.empty()) t.erase(t.begin());
            r++;
            t += s[r];
        }
        return (st.size() == (1<<k));
    }
};