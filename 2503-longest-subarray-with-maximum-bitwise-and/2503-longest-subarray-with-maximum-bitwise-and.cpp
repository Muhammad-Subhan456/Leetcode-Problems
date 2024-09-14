class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int count=0, MAX=0;
    int n = nums.size();
    vector<int>duplicate = nums;
    sort(duplicate.begin(),duplicate.end());
    int ele = duplicate[n-1];
    for(int i=0; i<nums.size();++i){
        if(nums[i]==ele) count++;
        else count=0;
        MAX = max(MAX,count);
    }
    return MAX;
    }
        
};