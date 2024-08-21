class Solution {
public:
    bool doesAliceWin(string s) {
        for(int i=0; i < s.size();++i){
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                return true;
        }
    return false;
    }
};