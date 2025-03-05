class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        for(long long i=0; i < n; ++i)
            ans += i*4;
        return ans;
        
    }
};