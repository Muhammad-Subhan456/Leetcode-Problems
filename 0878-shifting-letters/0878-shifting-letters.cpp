class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
    vector<long long unsigned int>freq(shifts.size(),0);
    for(int i=0; i < shifts.size();++i)
        freq[i] = shifts[i];
    for(int i= (s.size()-2);i>=0;--i){
        freq[i] = freq[i] + freq[i+1];
    } 
    for(int i=0; i < s.size(); ++i){
        if(s[i] + freq[i]<='z'){
        s[i] = s[i] + freq[i];
        }
        else{
            s[i] = (((s[i] + freq[i])-97)%26)+97;
        }
    }
    return s;
    }
};