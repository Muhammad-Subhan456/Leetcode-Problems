class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0; i < n; i++){
            int lo=i+1, hi = n-1;
            while(lo < hi){
                if(nums[i]==(-nums[lo])-nums[hi]){
                    vector<int> triple = {nums[i],nums[lo],nums[hi]};
                    if(s.find(triple) == s.end()){
                    ans.push_back(triple);
                    s.insert(triple);
                    }

                    lo++;
                    hi--;
                }
                else if(nums[i] < (-nums[lo])-nums[hi]) lo++;
                else hi--;
            } 
        }
        return ans;
    }
};