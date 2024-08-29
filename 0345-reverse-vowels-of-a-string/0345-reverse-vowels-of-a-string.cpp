class Solution {
public:
    bool isvowel(char ch){
 if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' ||
    ch=='A' ||ch=='E' ||ch=='I' ||ch=='O' ||ch=='U')
        return true;
    return false;
    }
    string reverseVowels(string s) {
    int lo=0, hi = s.size()-1;
    while(lo<hi){
        if(isvowel(s[lo]) && isvowel(s[hi]))
            swap(s[lo++],s[hi--]);
        if(!isvowel(s[lo]))
            lo++;
        if(!isvowel(s[hi]))
            hi--;
    }
    return s;
    }
};