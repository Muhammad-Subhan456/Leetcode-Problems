class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>mul;
        for(auto c : nums) if(c % k == 0) mul.insert(c);
        for(int i = k; i <= 100; i += k) if(mul.find(i) == mul.end()) return i;
        return (*mul.rbegin()+k);
    }
};