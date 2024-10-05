class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    long long ans=0;
    sort(skill.begin(),skill.end());
    int lo=0, hi = skill.size()-1;
    int check = skill[lo]+skill[hi];
    while(lo<=hi){
        if(skill[lo]+skill[hi]!=check) return -1;
        ans+=(skill[lo]*skill[hi]);
        lo++,hi--;
    }
    return ans;
    }
};