class Solution {
public:
    int minOperations(vector<int>& nums) {
    // if 1 exist in array
    int n = nums.size();
    int cnt = count(nums.begin(),nums.end(),1);
    if(cnt>=1) return (n-cnt);

    // minimal length of subarray with gcd = 1
    int mini = INT_MAX;
    for(int i=0;i < n; ++i){
        int currgcd = nums[i];
        for(int j=i ; j < n ; ++j){
            currgcd = gcd(currgcd,nums[j]);
            if(currgcd==1){
                mini = min(mini,j-i+1);
                break;
            }
        }
    }
    if(mini == INT_MAX){
        return -1;
    }
    return (mini-1)+(n-1);

    }
};