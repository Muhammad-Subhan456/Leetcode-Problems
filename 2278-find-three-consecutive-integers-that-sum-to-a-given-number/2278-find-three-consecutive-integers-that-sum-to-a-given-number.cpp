class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> result;
        if(num%3==0){
            long long ans  = num/3;
            result.push_back(ans-1);
            result.push_back(ans);
            result.push_back(ans+1);
            return result;
        }
        return {};
    }
};