class Solution {
public:
    int numSteps(string s) {
        int n = s.size()-1;
        int i = n,cnt=0;
        while(i > 0){
            if(s[i] == '0'){
                i--;
                cnt++;
            }
            else{
              //  if(i ==0 && s[i] == '1') return cnt;
                cnt += 2;
                i--;
                while(i >= 0 && s[i] != '0'){
                    cnt++;
                    i--;
                }
                if(i >= 0) s[i] = '1';
            }
        }
        return cnt;
    }
};