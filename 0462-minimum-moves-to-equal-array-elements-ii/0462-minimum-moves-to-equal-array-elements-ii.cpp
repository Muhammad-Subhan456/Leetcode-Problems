class Solution {
public:
    int minMoves2(vector<int>& a) {
        sort(a.begin(),a.end());
        int n = a.size();
        int med = 0;
        if(n&1) med = a[n/2];
        else med = (a[n/2] + a[(n/2)-1])/2;
        int steps = 0;
        for(auto &c : a){
            if(c <= med)
            steps += (med-c);
            else steps += (c-med);
        }
        return steps;
    }
};