class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = INT_MIN, mini = INT_MAX;
        for(auto &c : nums){
            maxi = max(maxi,1LL*c);
            mini = min(mini,1LL*c);
        }
        return 1LL*(maxi-mini)*k;
    }
};