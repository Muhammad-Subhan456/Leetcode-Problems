class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), l = 0 , r = 0, mini = INT_MAX, maxi = INT_MIN;
        map<int,int>mp;
        for(; r < n; r++){
            mp[nums[r]]++;
            mini = min(mini, mp[nums[r]]);
            // cout << mini << '\n';
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            if(mini <= k){
                maxi = max(maxi,r-l+1);
                // cout << "ok";
            }
        }
        // for(auto c : mp) cout << c.first << ' ' << c.second << '\n';
        return maxi;
    }
};