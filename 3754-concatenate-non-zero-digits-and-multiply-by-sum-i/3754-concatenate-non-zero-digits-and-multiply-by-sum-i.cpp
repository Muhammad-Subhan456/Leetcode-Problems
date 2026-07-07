class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        while(n > 0){
            int mod = n % 10;
            if(mod > 0) s += (mod+'0');
            n/=10;
        }
        if(s.size()==0) return 0ll;
        int sum = 0;
        for(auto c : s) sum += (c-'0');
        reverse(s.begin(),s.end());
        long long x = stoll(s);

        return x*sum*1ll;
    }
};