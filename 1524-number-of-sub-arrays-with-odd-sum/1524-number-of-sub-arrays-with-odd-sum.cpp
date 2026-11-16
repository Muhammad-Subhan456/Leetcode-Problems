class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ps = 0, oc = 0, ec =1 , res = 0;
        int MOD = 1e9+7;
        for(auto n : arr){
            ps += n;
            if(ps%2==0){
                res = (res + oc)% MOD ;
                ec += 1;
            }
            else{
                res = (res + ec) % MOD;
                oc += 1;
            }
        }
        return res % MOD;

    }
};