class Solution {
public:
    double pow(double x, long long n){
    if(n==0) return 1;
    if(n%2==0){
        double result = pow(x,n/2);
        return result*result;
    }
    else{
        double result = pow(x,(n-1)/2);
        return x*result*result;
    }
    }
    double myPow(double x, int n) {
    long long N=n;
    if(N<0) x = 1/x , N=-N;
    return pow(x,N);
    }
};