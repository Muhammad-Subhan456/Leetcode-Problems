class Solution {
public:
    string makeFancyString(string s) {
    stack<char>c;
    string ans="";
    int count=0;
    for(int i=0; i < s.size();++i){
        if(c.empty()){
            c.push(s[i]);
            ans += s[i];
        }
        else
        {
            if(c.top()==s[i]){
                count++;
                if(count>=2){
                    continue;
                } 
            }
            else{

                count=0;
            }
            c.push(s[i]);
            ans+=s[i];
        }
    }
    return ans;
            
    }
};
