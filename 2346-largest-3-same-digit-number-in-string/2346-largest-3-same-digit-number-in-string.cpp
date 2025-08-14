class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size();
        char c = '\0';
        int maxi = 0;
        for(int i=1;i < n-1; ++i){
            if(s[i-1]==s[i] && s[i]==s[i+1]){
                int len = s[i-1]+s[i]+s[i+1];
                if(len >= maxi){
                    c = s[i];
                    maxi = len;
                }
            }
        }
        if(c== '\0' ) return "";
        string ans(3,c);
        return ans;
    }
};