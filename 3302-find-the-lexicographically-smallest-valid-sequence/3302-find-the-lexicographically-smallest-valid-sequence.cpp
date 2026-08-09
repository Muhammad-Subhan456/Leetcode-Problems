class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<int>last(m,-1);
        int j = m-1;
        for(int i = n-1; i>=0; i--){
            if(w1[i]==w2[j]) {
                last[j] = i;
                j--;
                if(j < 0) break;
            }
        }
        bool change = false;
        j = 0;
        vector<int>res;
        for(int i=0 ;i < n; ++i){
            if(j==m) break;
            if(w1[i]==w2[j]) {
                res.push_back(i);
                j++;
            }
            else if(!change and (j==m-1 or last[j+1] > i )  ){
                change = true;
                res.push_back(i);
                j++;
            }
        }
        if(res.size()== m) return res;
        return {};
    }
};