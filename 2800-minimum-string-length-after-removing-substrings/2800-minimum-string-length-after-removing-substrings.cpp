class Solution {
public:
    int minLength(string s) {
    stack<char> store;
    for(int i=0; i < s.size(); ++i){
    if(!store.empty() && s[i]=='B' && store.top()=='A')
        store.pop();
    else if(!store.empty() && s[i]=='D' && store.top()=='C')
        store.pop();
    else
        store.push(s[i]);
    }
    return store.size();
    }
};