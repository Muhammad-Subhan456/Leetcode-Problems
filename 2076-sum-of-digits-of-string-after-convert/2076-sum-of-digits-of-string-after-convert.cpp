class Solution {
public:
    int getLucky(string s, int k) {
           int sum=0;

        string ans="";
        for(int i=0 ; i<s.size();++i){
            ans+=to_string(s[i]-'a'+1);
        }
        while(k--){
        sum=0;
        for(int i=0; i < ans.size();++i){
            sum+=(ans[i]-'0');
        }
            ans.clear();
            ans = to_string(sum);
        }
    return sum;
    }
};