class Solution {
public:
    int minChanges(string s) {
        int i=0,j=1,count=0;

        for(int i=0; i < s.size();++i){
            if(s[i]!=s[++i])
                count++;
            }
        return count;
    }
};