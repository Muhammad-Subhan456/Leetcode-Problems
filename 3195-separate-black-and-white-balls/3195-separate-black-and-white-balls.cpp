class Solution {
public:
    long long minimumSteps(string s) {
    long long ans=0,count=0;
    for(int i=0; i<s.size();++i)
    s[i]=='1' ? count++ : ans+=count;
    return ans;
    }
};