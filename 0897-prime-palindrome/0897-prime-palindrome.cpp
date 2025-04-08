class Solution {
public:
    bool isPalindrome(int n) {
        string s = to_string(n);
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i*i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        while (true) {
            if (isPalindrome(n) && isPrime(n)) return n;
            n++;
            if (n > 11 && to_string(n).size() % 2 == 0) {
                n = pow(10, to_string(n).size());
            }
        }
        return -1;
    }
};
