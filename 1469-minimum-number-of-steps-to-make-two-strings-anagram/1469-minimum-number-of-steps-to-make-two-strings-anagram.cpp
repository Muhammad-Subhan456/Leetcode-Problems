class Solution {
public:
    int minSteps(string s, string t) {
      map<char,int>mp1;
        map<char,int>mp2;
        int sum=0;
        for(auto c : s) mp1[c]++;
        for(auto c : t) mp2[c]++;
        for(auto &p : mp2){
            int mini = INT_MAX;
            if(mp1[p.first]){
                mini = min(p.second,mp1[p.first]);
                p.second -= mini;
                mp1[p.first] -= mini;
            }
        }
        for(auto p : mp1){
            sum += p.second;
        }
        return sum;  
    }
};