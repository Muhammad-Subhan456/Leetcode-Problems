class Solution {
public:
    string removeStars(string s) {
       stack<char>store;
        string ans;
        for(int i=0;i<s.size();++i){
            if(s[i]=='*')
                store.pop();
            else    
                store.push(s[i]);
        }
        if(store.empty())
            return "";
        else{
            while(!store.empty()){
                ans.push_back(store.top());
                store.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};