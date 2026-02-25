class Solution {
public:
struct cmp{
    bool operator()(const int &a,const int &b){
       int cntA = __builtin_popcount(a);
       int cntB = __builtin_popcount(b);
       if(cntA == cntB) return a < b;
        return cntA < cntB;
    }
};
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(),arr.end(),cmp());
        return arr;
    }
};