class Solution {
public:
    
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n = a.size(), m = b.size();
        int s = max(n,m),carry=0;
        int sum=0;
        string t;
        for(int i=0; i < s; ++i){
        int one=0,two = 0;
        if(i < n) one = a[i]-'0';
        if(i < m) two = b[i]-'0';
        sum = one + two + carry;
        t += char(sum%2 + '0');
        carry = sum/2;
        }
        if(carry) t += '1';
        reverse(t.begin(),t.end());
        return t;
    }
};