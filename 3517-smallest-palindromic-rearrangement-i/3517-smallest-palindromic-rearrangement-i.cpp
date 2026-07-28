class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string res(n,'*');
        map<char,int>mp;
        for(auto &c : s) mp[c]++;
        int i=0;
        for(auto &p : mp){
            if(p.second & 1){
                p.second--;
                res[n/2] = p.first;
            }
            int put = p.second/2;
            for(int j=0 ; j < put; ++j){
                res[i] = p.first;
                res[n-i-1] = p.first;
                i++;
            } 
            

        }
        return res;
    }
};