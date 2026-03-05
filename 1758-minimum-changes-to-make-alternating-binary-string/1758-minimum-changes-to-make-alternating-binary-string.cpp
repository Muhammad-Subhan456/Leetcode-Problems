class Solution {
public:

int miniii(string &s,int &cnt){
    int n = s.size();
        for(int i=1; i < n; ++i){
            if(s[i] == s[i-1]){
                if(s[i] == '0') s[i] = '1';
                else s[i] = '0';
                cnt++;
            }
        }
    return cnt;
}
    int minOperations(string s) {
        string s1 = s;
        string s2 = s;
        string s3 = s;
        int cnt = 0;
        // pass 1 
       int min1 = miniii(s1,cnt);
        //pass 2
        if(s2[0] == '0'){
            cnt = 1;
            s2[0] = '1';
            min1 = min(min1,miniii(s2,cnt));
        }
        else{
            cnt = 1;
            s2[0] = '0';
            min1 = min(min1,miniii(s2,cnt));
        }
        // pass 3
        reverse(s3.begin(),s3.end());
        string s4 = s3;
        cnt = 0;
    
        int min2 = miniii(s3,cnt);
        // pass 4
        if(s4[0] == '0'){
            cnt = 1;
            s4[0] = '1';
            min2 = min(min2,miniii(s4,cnt));
        }
        else{
            cnt = 1;
            s4[0] = '0';
            min2 = min(min2,miniii(s4,cnt));
        }
        cout << min2;
        return min(min1,min2);
    }
};