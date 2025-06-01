class Solution {
public:
    string frequencySort(string s) {
    priority_queue<pair<int,char>>pq;
    map<char,int>m;
    for(auto e : s) m[e]++;

    for(auto p : m){
        pq.push({p.second,p.first});
    }
    s.clear();
    while(!pq.empty()){
        pair<int,char> p = pq.top();
        pq.pop();
        for(int i=0; i < p.first; ++i){
            s += p.second;
        }

    }
    return s;
    }
};