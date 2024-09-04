class Solution {
public:
    string check(string s){
        stack<char>stk;
        for(int i=0; i < s.size();++i){
            if(s[i]=='#'){
                if(!stk.empty())
                    stk.pop();
            }
            else
                stk.push(s[i]);
        }
        s.clear();
        while(!stk.empty()){
            s+=stk.top();
            stk.pop();
        }
        return s;
    }
    bool backspaceCompare(string s, string t) {
        s = check(s);
        t = check(t);
        return s==t;
    }
};