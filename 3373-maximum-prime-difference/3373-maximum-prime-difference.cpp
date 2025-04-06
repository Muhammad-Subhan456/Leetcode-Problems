class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n=101;
        vector<bool>isPrime(n,true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i <= n; ++i){
            if(isPrime[i]){
                for(int j = 2*i; j <=n; j +=i)
                    isPrime[j] = false;
            }
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0 ; i < nums.size(); ++i){
            if(isPrime[nums[i]]){
                mini = min(i,mini);
                maxi = max(i,maxi);
            }
        }
        return (maxi-mini);

    }
};