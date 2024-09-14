class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int count=0, MAX=0;
    int ele = *max_element(nums.begin(),nums.end());
    for(int i=0; i<nums.size();++i){
        if(nums[i]==ele) count++;
        else count=0;
        MAX = max(MAX,count);
    }
    return MAX;
    }
        
};