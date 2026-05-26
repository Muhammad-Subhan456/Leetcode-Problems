class Solution {
public:

    int numberOfSpecialChars(string word) {
        vector<pair<int,int>>freqA(26,{0,-1});
        vector<pair<int,int>>freqa(26,{0,0});
        int n = word.size();
        for(int i=0; i < n; ++i){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                int j = word[i] -'A';
                freqA[j].first++;
                if(freqA[j].second == -1){
                    freqA[j].second = i; 
                }
            }
            else if(word[i] >= 'a' && word[i] <= 'z') {
                int j = word[i] -'a';
                freqa[j].first++;
                freqa[j].second = i;

            }
        }
        int cnt = 0;
        for(int i=0; i < 26; ++i){
            if(freqA[i].first > 0 && freqa[i].first > 0 && freqa[i].second < freqA[i].second) cnt++;
        }
        return cnt;
        
    }
};