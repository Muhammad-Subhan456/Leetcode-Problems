class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(n > k){
        string t;   
            
            for(int i=0; i < n;){
                int sum = 0;
                
                for(int j=0; (j < k && i < n) ; ++j){
                    sum += s[i++] - '0';
                    // cout << sum << '\n';
                }
                t += to_string(sum);
                // cout << t << '\n';
                
            }
            // n = t.size();
            // cout << t << ' ' << n;
            //  break;
            s = t;
            n = s.size();

            }
        return s;
        
    }
};