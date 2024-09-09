class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>ans;
        int i=0;
        while(i < s.size()){
            if(isdigit(s[i])){
                int num=0;
                while(i < s.size() && isdigit(s[i])){
                    num = num*10+ (s[i]-'0');
                    ++i;
                }
                ans.push_back(num);
            }
            else
                ++i;
        }
        for (int i = 0; i < ans.size() - 1; ++i) {
            if (ans[i + 1] <= ans[i]) {
                return false;
            }
        }
        
        return true;
    }
};