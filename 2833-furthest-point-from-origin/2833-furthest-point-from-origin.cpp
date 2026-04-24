class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, e = 0;
        int n = moves.size();
        for(auto &c : moves){
            if(c == 'L') l++;
            else if(c== 'R') r++;
            else e++;
        }
        if(l == 0 && r == 0) return n;
        if(l > r){
            return l + e - r;
        }
        else if(r > l) return r + e - l;
        else return e;
    }
};