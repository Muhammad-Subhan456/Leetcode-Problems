class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        set<int>s;
        for(auto ele : arr)
            m[ele]++;
        for(auto pair : m)
            s.insert(pair.second);
        if(s.size()==m.size())
            return true;
        return false;
    }
};