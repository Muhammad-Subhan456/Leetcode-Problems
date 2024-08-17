class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi = numbers.size()-1;
        vector<int>ans;
        while(lo <= hi){
            if(numbers[lo]+numbers[hi]==target){
                ans.push_back(lo+1);
                ans.push_back(hi+1);
                return ans;
            }
            else if(numbers[lo]+numbers[hi]<target)
                lo++;
            else
                hi--;
        }
        return ans;
            
    }
};