class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2; i < nums.size(); ++i){
            if(a1.back() > a2.back()) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }
        int i=0;
        for(; i < a1.size(); ++i) nums[i] = a1[i];
        for(int j=0; j < a2.size(); ++j) 
        nums[i++] = a2[j];
        return nums;
    }
};
            
            

