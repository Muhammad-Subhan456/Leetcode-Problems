class Solution {
public:
    int minChanges(string s) {
        int i=0,j=1,count=0;

        for(int k=0; k < (s.size()/2);++k){
            if(s[i]!=s[j])
                count++;
            i+=2;
            j+=2;
        }
        return count;
    }
};