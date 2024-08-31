class Solution {
public:
    int minSwaps(string s) {
        int a=0,b=0;
        stack<char>store;
        for(int i=0;i<s.size();++i){
            if(s[i]=='['){
                store.push(s[i]);
                a++;
            }
            else{
                if(!store.empty() && store.top()=='['){
                    store.pop();
                    a--;
                }
                else{
                    store.push(s[i]);
                    b++;
                }
                    
            }
        }
        int ans = (a+1)/2 + (b+1)/2;
        return ans/2;
    }
};