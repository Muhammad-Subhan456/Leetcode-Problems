class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string>s;
        int n = word.size();
        for(int i=0; i < n; ++i){
            string t;
            for(int j=i; j < n; ++j){
                t += word[j];
                s.insert(t);
            }
        }
        int cnt = 0;
        for(auto &c : patterns){
            if(s.find(c) != s.end()) cnt++;
        }
        return cnt;
    }
};