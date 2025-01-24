class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
    int count=0;
    vector<long long> prefix(nums.size()+1,0);
    for(int i=0; i < nums.size(); ++i){
       prefix[i+1] = prefix[i] + nums[i];
    } 
    for(int i=1; i < nums.size(); ++i){
        if(prefix[i] >= prefix[nums.size()]-prefix[i]) count++;
    }
    return count;
    }
};