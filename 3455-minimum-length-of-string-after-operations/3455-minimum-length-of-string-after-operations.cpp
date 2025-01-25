class Solution {
public:
    int minimumLength(string s) {
    map <char,int>m;
    int count =0;
    for(int i=0; i < s.size(); ++i){
        m[s[i]]++;
    }
    for(auto pair : m){
        if(pair.second <=2) count += pair.second;
        else if(pair.second%2==0) count+=2;
        else count+=1;
    }
    return count;
    }
};