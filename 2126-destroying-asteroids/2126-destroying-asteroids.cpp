class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        long long m = mass;
        sort(a.begin(),a.end());
        for(auto &c : a){
            if(m >= c){
                m += c;
            }
            else return false;
        }
        return true;
    }
};