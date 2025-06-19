class Solution {
public:
    int countSubarrays(vector<int>& nums, int k){
        int l=0,r=0, n = nums.size(),cnt=0;
        map<int,int>m;
        while(r < n){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0) m.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    int x = countSubarrays(nums,k);
    int y = countSubarrays(nums,k-1);
    return x-y;
        
    }
};