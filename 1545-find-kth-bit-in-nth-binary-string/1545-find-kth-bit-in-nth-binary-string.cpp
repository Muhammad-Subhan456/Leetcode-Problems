class Solution {
public:
    void invert(string &s){
        for(auto &c : s){
            if(c == '0') c = '1';
            else c = '0';
        }
    }
    char findKthBit(int n, int k) {
        vector<string>str(n+1);
        str[1] = "0";
       for(int i=2; i<=n; ++i){
        string t = str[i-1] + "1";
        invert(str[i-1]);
        reverse(str[i-1].begin(),str[i-1].end());
        t += str[i-1];
        str[i] = t;
       }
    return str[n][k-1];
    }
};