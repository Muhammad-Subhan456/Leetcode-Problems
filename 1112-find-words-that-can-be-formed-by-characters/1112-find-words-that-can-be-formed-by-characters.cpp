class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq1(26,0);
        int count=0;
        for(auto ele : chars)
            freq1[ele-'a']++;
        for(int i=0; i < words.size();++i){
        int d=-1;
        vector<int>freq2= freq1;
            for(int j=0;j<words[i].size();++j){
                freq2[words[i][j]-'a']--;
            }
            for(auto ele : freq2){
                if(ele<0){
                    d=1;
                    break;
                }
            }
            if(d==-1)
                count+=words[i].size();
        }
    return count;
    }
};