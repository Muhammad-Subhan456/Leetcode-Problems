class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s;
        for(int i=0 ; i < nums.size();++i){
            s += to_string(nums[i]);
        }
        nums.clear();
        for(int i=0; i < s.size();++i){
            nums.push_back(s[i]-'0');
        }
        return nums;
    }
};