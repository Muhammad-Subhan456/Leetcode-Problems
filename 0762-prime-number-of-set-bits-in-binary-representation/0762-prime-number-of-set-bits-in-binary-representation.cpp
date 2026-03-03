class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        const int n = 30;
        vector<bool>isPrime(n,true);
        isPrime[0] = isPrime[1] = false;
            for (int i = 2; i < n; ++i) {
                if (isPrime[i]) {
                    for (int j = 2 * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        int cnt = 0;
        for(int i = left; i <= right; ++i){
            int x = __builtin_popcount(i);
            if(isPrime[x]) cnt++;
        }
        return cnt;
    }
};