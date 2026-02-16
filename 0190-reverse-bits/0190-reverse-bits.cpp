class Solution {
public:
    using ll = long long;
    ll dec(string s){
        ll sum=0;
        for(ll i=0; i <= 31;++i){
            sum += (1LL*(s[i]-'0')*(1<<i));
        }
        return sum;
    }
    int reverseBits(int n) {
        bitset<32>b(n);
        string s = b.to_string();
        cout << s;
        return dec(s);
    }
};