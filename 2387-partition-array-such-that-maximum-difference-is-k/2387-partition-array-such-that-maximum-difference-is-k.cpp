class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lastcur = n-1,ans=0;
        for(int i=n-1; i>=0; --i){
            if(nums[lastcur]-nums[i]>k){
                ans++;
                lastcur=i;
            }
        }
        return ans+1;
    }
};