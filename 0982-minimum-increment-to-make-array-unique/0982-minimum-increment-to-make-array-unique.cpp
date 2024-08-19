class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0; i < nums.size()-1;++i){
            while(nums[i]>=nums[i+1]){
                nums[i+1]++,count++;
            }
        }
        return count;
    }
};