class Solution {
public:
    int countSub(vector<int>& nums, int k){
        int l=0,r=0,n=nums.size(),cnt=0,ans=0;
        while(r < n){
            if(nums[r]&1) cnt++;
            while(cnt>k){
                if(nums[l]&1) cnt--;
                l++;
            }
            ans += (r-l+1);
            r++;
            
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
    int x = countSub(nums,k);
    int y = countSub(nums,k-1);
    return x-y;
    }
};