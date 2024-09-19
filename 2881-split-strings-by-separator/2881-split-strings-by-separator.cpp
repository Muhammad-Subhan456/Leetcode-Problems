class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    string name;
    vector<string>ans;
    for(int i=0; i<words.size();++i){
    stringstream ss(words[i]);
    while(getline(ss,name,separator)){
        if(name!="")
        ans.push_back(name);
    }
    }
    return ans;
    }
};