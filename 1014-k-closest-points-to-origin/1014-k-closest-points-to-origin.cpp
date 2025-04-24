class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
priority_queue<pair<int,int>> pq;
vector<vector<int>> result;
    for(int i=0; i < k; ++i){
        int ans =(((0-points[i][0])*(0-points[i][0])) + ((0-points[i][1])*(0-points[i][1])));

        pq.push({ans,i});
    }

    for(int i = k; i < points.size(); ++i){
        int ans =(((0-points[i][0])*(0-points[i][0])) + ((0-points[i][1])*(0-points[i][1])));

        if(ans <= pq.top().first){
            pq.pop();
            pq.push({ans,i});
        }
    }


    while(!pq.empty()){
        pair<int,int>p;
        p = pq.top();
        pq.pop();

        result.push_back(points[p.second]);
    }
    return result;







    }
};