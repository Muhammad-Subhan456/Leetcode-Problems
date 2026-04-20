class Solution {
public:
    int maxDistance(vector<int>& c) {
        int n = c.size();
        int maxi = 0;
        for(int i=0; i < n; ++i){
            for(int j = i; j < n ; ++j){
                if(c[i] != c[j]) maxi = max(maxi, abs(i-j));
            }
        }
        return maxi;
    }
};