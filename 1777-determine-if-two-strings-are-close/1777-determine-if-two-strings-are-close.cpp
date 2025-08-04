class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size() ) return false;
        vector<int>freq1(26,0),freq2(26,0);
        set<char>s1,s2;
        for(auto c : word1){
            freq1[c-'a']++;
            s1.insert(c);
        }
        for(auto c : word2){
            freq2[c-'a']++;
            s2.insert(c);
        } 
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return (freq1==freq2 && s1==s2);
    }
};