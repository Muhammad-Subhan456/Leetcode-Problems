class Solution {
public:
    int numberOfSubstrings(string s) {
       int l=0,r=0,cnt=0,n=s.size();
       vector<int>ls(3,-1);
       for(int i=0; i < n; ++i){
        char c = s[i]-'a';
        ls[c] = i;
        if(ls[0] != -1 && ls[1] != -1 &&ls[2] != -1){
            cnt += (1 + *min_element(ls.begin(),ls.end()));
        }
       }
        return cnt;
    }
       
};