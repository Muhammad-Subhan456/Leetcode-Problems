class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int count=0;
        int max=0;
        for(auto ele : s){
            if(ele=='('){
                st.push(ele);
                count++;
                if (max<count){
                    max=count;
                }
            }
            else if (ele==')'){
                st.pop();
                count--;
            }
        }
        return max;
    }
};