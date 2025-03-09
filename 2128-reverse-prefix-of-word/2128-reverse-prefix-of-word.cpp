class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        int flag=-1;
        for(; i < word.size();++i){
            if(word[i]==ch) {
                flag=1;
                break;
            }
        }
        if(flag==1) reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};