class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size(),temp=0;
        vector<int>o(n);
        for(int i=0; i < n; ++i){
            if(nums[i] == 0) o[i] = nums[i];
            if(nums[i] > 0){
                temp = nums[i]%n;
                o[i] =  nums[(i+temp)%n];
            }
            else{
                temp = abs(nums[i]);
                temp = temp%n;
               // cout << temp << '\n';
                temp = i - temp;
                if(temp >= 0) o[i] = nums[temp];
                else
                o[i] =  nums[n+temp];
            }
        }
        return o;       
    }
};