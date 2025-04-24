class Solution {
public:
    int calculate(int x2,int y2){
        int x1=0,y1=0;
        return (((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
priority_queue<pair<int,int>> pq;
vector<vector<int>> result;
    for(int i=0; i < k; ++i){
        int ans = calculate(points[i][0],points[i][1]);
        pq.push({ans,i});
    }

    for(int i = k; i < points.size(); ++i){
        int ans = calculate(points[i][0],points[i][1]);
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