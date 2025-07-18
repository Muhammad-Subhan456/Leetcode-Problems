class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto &group : m) {
            ans.push_back(move(group.second));
        }
        
        return ans;
    }
};

