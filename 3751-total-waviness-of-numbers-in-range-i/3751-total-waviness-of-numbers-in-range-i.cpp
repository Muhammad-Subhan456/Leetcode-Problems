class Solution {
public:
    
    int wavy(string &s){
        int n = s.size();
        int cnt = 0;
        for(int i=1; i < n-1; ++i){
            if(s[i] > s[i+1] && s[i] > s[i-1]) cnt++;
            if(s[i] < s[i+1] && s[i] < s[i-1]) cnt++;
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        string s = "";
        for(int i= num1; i <= num2; ++i){
            if(i < 99) continue;
            s = to_string(i);
            cnt += wavy(s);
        }
        return cnt;

    }
};