class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto ele : tokens){
            if(ele != "+" && ele != "-" && ele != "*" && ele != "/"){
                st.push(stoi(ele));
            }
            else{
                int ele1 = st.top();
                st.pop();
                int ele2 = st.top();
                st.pop();
                if(ele == "+")
                st.push(ele1+ele2);
                if(ele == "-")
                st.push(ele2-ele1);
                if(ele == "*")
                st.push(ele1*ele2);
                if(ele == "/")
                st.push(ele2/ele1);

            }
        }
        return st.top();

    }
};