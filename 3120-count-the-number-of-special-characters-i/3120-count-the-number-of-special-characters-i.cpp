class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>freqA(26,0);
        vector<int>freqa(26,0);
        for(auto &c : word){
            if(c >= 'A' && c <= 'Z'){
                freqA[c - 'A']++;
            }
            else if(c >= 'a' && c <= 'z') freqa[c-'a']++;
        }
        int cnt = 0;
        for(int i=0; i < 26; ++i){
            if(freqA[i] > 0 && freqa[i] > 0) cnt++;
        }
        return cnt;
    }
};