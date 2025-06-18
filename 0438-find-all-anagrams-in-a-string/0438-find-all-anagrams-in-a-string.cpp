class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int k = p.size();
        int l=0,r=k-1,n=s.size();
        map<char,int>ms;
        map<char,int>mp;
        for(auto c : p) mp[c]++;
        for(int i=0; i <= r; i++){
            ms[s[i]]++;
        }
        if(mp==ms) ans.push_back(l);
        while(r < n){
            ms[s[l]]--;
            if(ms[s[l]]==0) ms.erase(s[l]);
            l++;
            r++;
            ms[s[r]]++;
            if(ms==mp) ans.push_back(l);
        }
        return ans;
    }
};