class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int miniOdd = INT_MAX;
        int n = nums1.size();
        int even = 0 , odd = 0;
        for(auto & i : nums1){
            if(i & 1){
                odd++;
                miniOdd = min(miniOdd,i);
            }
            else even++;
        }
        if(n == even || n == odd) return true;
        for(int i=0; i < n; ++i){
            if(!(nums1[i] & 1) && (nums1[i] - miniOdd < 1)) return false;
        }
        return true;
    }
};
            