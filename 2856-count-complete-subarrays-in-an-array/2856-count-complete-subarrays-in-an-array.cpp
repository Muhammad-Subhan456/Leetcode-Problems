class Solution {
public:
int subarr(vector<int>& nums, int k){
    int l=0,r=0, n = nums.size(),cnt=0;
    map<int,int>mp;
    while(r < n){
        mp[nums[r]]++;
        while(mp.size() > k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
        }
        cnt += (r-l+1);
        r++;
    }
    return cnt;
}
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s;
        for(auto &c : nums) s.insert(c);
        int k = s.size();
        int x = subarr(nums,k);
        int y = subarr(nums,k-1);
        return x-y;
    }
};