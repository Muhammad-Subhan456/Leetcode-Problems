class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        for(auto ele : students) q.push(ele);
        int count = 0;
        int i=0;
        while(q.size() > 0 && count != q.size()){
            if(q.front()==sandwiches[i]){
                count = 0;
                q.pop();
                i++;

            }
            else{
                int push = q.front();
                q.pop();
                q.push(push);
                count++;
            }
        }
        return q.size();
    }
};