class Solution {
public:
    char parseand(string s){
        if(s.find('f')!=string::npos){
            return 'f';
        }
        return 't';
    }
    char parseor(string s){
        if(s.find('t')!=string::npos){
            return 't';
        }
        return 'f';
    }
    char parsenot(string s){
        if(s=="f") return 't';
        return 'f';
    }
    bool parseBoolExpr(string expression) {
        string ans = "";
        string s = expression;
        stack<char>st;
        for(int i = 0 ; i < s.size(); ++i){
            if(s[i] != ')' && s[i] != ','){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                ans = "";
               // cout << ans << endl;
                while(st.top() != '(' && !st.empty()){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                char op = st.top();
               // cout << op << endl;
                st.pop();
                char oper;
                if(op == '&'){
                    oper = parseand(ans);
                }
                else if(op == '|'){
                    oper = parseor(ans);
                }
                else if(op == '!')
                    oper = parsenot(ans);
                st.push(oper);
            }
        }
       // cout << ans << endl;
        return st.top()=='t';
        
    }
};