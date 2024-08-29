class Solution {
public:
    string sortVowels(string s) {
        string t;
        string ans;
        for(int i=0 ; i < s.size();++i){
            if(s[i]=='a' ||
            s[i]=='e' ||
            s[i]=='i' ||
            s[i]=='o' ||
            s[i]=='u' ||
            s[i]=='A' ||
            s[i]=='E' ||
            s[i]=='I' ||
            s[i]=='O' ||
            s[i]=='U')
            t.push_back(s[i]);
        }
        sort(t.begin(),t.end());
        for(int i=0,j=0; i<s.size();++i){
             if(s[i]=='a' ||
            s[i]=='e' ||
            s[i]=='i' ||
            s[i]=='o' ||
            s[i]=='u' ||
            s[i]=='A' ||
            s[i]=='E' ||
            s[i]=='I' ||
            s[i]=='O' ||
            s[i]=='U'){
            ans.push_back(t[j++]);

            }
            else
            ans.push_back(s[i]);
        }
    return ans;
    }

};