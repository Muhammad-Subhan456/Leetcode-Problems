class Solution {
public:
    string reverseWords(string s) {
    string dum;
    vector<string>ans;
    int i=0;
    for(; i < s.size(); ++i){
        while(i < s.size() && s[i]==' ')i++;
        while(i < s.size() && s[i]!=' ')dum+=s[i++];
        if(!dum.empty()) ans.push_back(dum),dum="";
    }
    reverse(ans.begin(),ans.end());
    s.clear();
    for(auto ele : ans){
        s+=ele;
        s+=" ";
    }
    s.pop_back();
    return s;
    }
};