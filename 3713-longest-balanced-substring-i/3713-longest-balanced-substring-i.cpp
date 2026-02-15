class Solution {
public:
bool check(map<char,int>&mp){
    bool flag = true;
    int com=0;
    for(auto p : mp){
        if(flag){
            com = p.second;
            flag = false;
            continue;
        }
        if(p.second != com) return false;
    }
    return true;
}
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 1;
        for(int i=0; i < n; ++i){
            map<char,int>mp;
            for(int j=i; j < n; ++j){
                mp[s[j]]++;
                if(check(mp)) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};