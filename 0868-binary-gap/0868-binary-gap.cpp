class Solution {
public:


    int binaryGap(int n) {
        string s;
        int t = n;
        while(t > 0){
            s = char(t%2+'0') + s;
            t /= 2;
        }
        int maxi = 0;
        int prev = -1;
        for(int i = s.size()-1; i>=0; --i){
            if(s[i] == '1' && prev == -1) prev = i;
            if(s[i] == '1'){
                maxi = max(maxi,prev-i);
                prev = i;
            }
        }
        return maxi;
    }
};