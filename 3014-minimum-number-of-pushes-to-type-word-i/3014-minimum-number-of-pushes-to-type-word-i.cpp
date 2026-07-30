class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;
        int mod = n % 8;
        int div = n / 8;
        int cnt = 0;
        if(div == 1) cnt = (mod*2);
        else if(div == 2) cnt = (mod*3);
        else cnt = mod*4;
        while(div){
            cnt += (div*8);
            div--;
        }
        return cnt;
    }
};