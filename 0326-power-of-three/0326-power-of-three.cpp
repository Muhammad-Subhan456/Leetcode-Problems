class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int count=0;
      while(n){
            if(n<=3) break;
            int mod = n % 3;
            if(mod >= 1) return false;
        n /=3;
      }
    return n % 3==0 || n % 3==1;
    }
};