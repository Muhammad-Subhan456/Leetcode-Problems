class Solution {
public:
    int findTheWinner(int n, int k) {
    deque<int>q;
    for(int i=1; i <=n; ++i)
        q.push_back(i);
    while(q.size()>1){
        int t=k;
        while(t--){
            int ele = q.front();
            q.push_back(ele);
            q.pop_front();
        }
        q.pop_back();
    }
    return q.front();  
    }
};