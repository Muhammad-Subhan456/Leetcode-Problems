class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    set<char>s;
    int count=0;
    for(int i=0; i < allowed.size();++i)
        s.insert(allowed[i]);
    for(int i=0; i < words.size();++i){
        int check=-1;
        for(int j=0; j<words[i].size();++j){
            if(s.find(words[i][j])==s.end()){
                check=1;
                break;
            }
        }

        if(check==-1) count++;
    }
    return count;
    }
};