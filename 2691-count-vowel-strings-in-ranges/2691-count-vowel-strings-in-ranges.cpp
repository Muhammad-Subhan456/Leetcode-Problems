class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int>ans;
    int n = words.size();
    unordered_set<char>s = {'a','e','i','o','u'};
    vector<int>freq(n,0);
    for(int i=0; i <n;++i){
        if(s.find(words[i][words[i].size()-1])!=s.end() && s.find(words[i][0])!=s.end()){
            freq[i]++;
        }
    } 
    for(int i=1; i < n ; ++i){
        freq[i] = freq[i]+freq[i-1];
    } 
    for(int i=0; i < queries.size();++i){
        int l = queries[i][0];
        int r = queries[i][1];
    if(l!=0)
    ans.push_back(freq[r]-freq[l-1]);
    else
    ans.push_back(freq[r]);
    }

    return ans;
    }
};