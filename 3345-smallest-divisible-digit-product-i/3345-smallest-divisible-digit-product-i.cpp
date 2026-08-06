class Solution {
public:
    int prod(int n){
        string s = to_string(n);
        int mul = 1;
        for(auto &c : s) mul *= (c-'0');
        return mul;

    }
    int smallestNumber(int n, int t) {
            while(n){
                int mul = prod(n);
                if(mul % t == 0) return n;
                n++;
            }
            return 0;
    }
};