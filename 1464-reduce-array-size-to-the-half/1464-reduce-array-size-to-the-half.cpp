class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        priority_queue<int>pq;
        int count=0,sum=0;
        int n = arr.size();
        for(auto e : arr) m[e]++;

        for(auto p : m){
            pq.push(p.second);
        }
        // while(!pq.empty()){
        //     cout << pq.top() << " ";
        //     pq.pop();
        // }

        while(!pq.empty()){
            sum += pq.top();
            cout << pq.top() << " ";
            pq.pop();
                count++;
            if(sum >= (n/2)) return count;
            
            
        }


        return 0;
    }
};