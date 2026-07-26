class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>result;
        result.push_back(nums[0]);
        result.push_back(nums[1]);
        result.push_back(nums[2]);
        if(n-1 > 2){
        result.push_back(nums[n-1]);

        }
        if(n-2 > 2){
        result.push_back(nums[n-2]);

        }
        if(n-3 > 2){
        result.push_back(nums[n-3]);

        }
        for(auto c : result) cout << c << ' ';
        int maxi = INT_MIN;
        int nn = result.size();
        for(int i=0; i < nn; ++i){
            for(int j = i+1; j < nn; ++j){
                for(int k=j+1; k < nn; ++k){
                    maxi = max(maxi, result[i]*result[j]*result[k]);
                }
            }
        }
        return maxi;
    }
};