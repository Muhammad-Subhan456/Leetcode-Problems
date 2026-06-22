class Solution {
public:
    int maxNumberOfBalloons(string t) {
        map<char,int>mp;
        mp['b'] = 0;
        mp['a'] = 0;
        mp['l'] = 0;
        mp['o'] = 0;
        mp['n'] = 0;
        for(auto &c : t){
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
                mp[c]++;
        }
        mp['l'] /=2;
        mp['o'] /=2;
        int mini = INT_MAX;
        for(auto p : mp){
            mini = min(mini,p.second);
        }
        return mini;
    }
};