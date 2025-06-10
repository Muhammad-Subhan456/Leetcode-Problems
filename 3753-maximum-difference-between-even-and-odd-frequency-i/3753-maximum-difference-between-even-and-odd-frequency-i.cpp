class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        for(auto c : s){
            freq[c-'a']++;
        }
        int o= INT_MIN,ev=INT_MAX;
        for(auto e : freq){
            if(e==0) continue;
            if(e&1)o = max(e,o);
            else ev = min(ev,e);
        }
        return o-ev;
    }
};