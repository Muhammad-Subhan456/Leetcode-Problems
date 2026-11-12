class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int n = nums.size();
        int ans = 1;
        for(int i=0; i < n; ++i){
            int Incnt = 1 , Decnt = 1;
            for(int j=i; j < n-1; ++j){
                if(nums[j] > nums[j+1]) Incnt++;
                else {
                    ans = max({ans,Incnt,Decnt});
                    Incnt = 0;
                }
                if(nums[j] < nums[j+1]) Decnt++;
                else{
                    ans = max({ans,Incnt,Decnt});
                    Decnt = 0;
                }
            }
            ans = max({ans,Incnt,Decnt});
        }
        return ans;
    }
};