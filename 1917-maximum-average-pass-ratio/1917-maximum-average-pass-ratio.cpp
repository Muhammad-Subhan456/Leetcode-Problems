class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int es) {
    auto gain = [](int p,int q){
        return (double)(p+1)/(q+1) - (double)p/q;
    };
    priority_queue<tuple<double,int,int>>pq;
    double sum = 0.0;
    int n = c.size();
    for(int i=0; i < n; ++i){
        int p = c[i][0],q = c[i][1];
        sum += (double)p/q;
        pq.push({gain(p,q),p,q});
    }
    while(es--){
        auto [g,p,q] = pq.top();
        pq.pop();
        sum -= (double)p/q;
        p++,q++;
        sum += (double)p/q;
        pq.push({gain(p,q),p,q});
    }
    return sum/n;
    }
};