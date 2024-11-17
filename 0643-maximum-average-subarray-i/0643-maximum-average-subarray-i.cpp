class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int lo=0,hi=k-1;
    double sum=0,avg=0;
    for(int i=lo;i<=hi;++i){
        sum += nums[i];
    }
    avg = sum/k;
    while(hi < nums.size()-1){
        sum-=nums[lo];
        lo++;
        hi++;
        sum+=nums[hi];
        if((sum/k)>avg)
            avg = sum/k;

    }
    return avg;
    }
};