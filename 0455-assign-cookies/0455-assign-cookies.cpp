class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(), m = s.size();
        int cnt=0;
        int k=0; 
        for(int i=0; ((i < n) && (k < m))  ; ++i){
            bool flag= true;
            if(s[k] >= g[i]){
                cnt++; k++;
                flag = false;
            }
            if(flag){

            while((k < m) && (s[k] < g[i])){
                k++;
            }
            if((k < m) && (i < n) && (s[k] >= g[i])){
                cnt++; k++;
            }
            }
        }
        return cnt;

    }
};