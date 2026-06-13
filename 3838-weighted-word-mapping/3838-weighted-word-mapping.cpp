class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string ans = "";
        for(auto & c : words){
            int sum = 0;
            for(auto &e : c){
                sum += w[e-'a'];
            }
            sum %= 26;
            ans += (char)(122-sum) ;
        } 
        return ans;  
    }
};