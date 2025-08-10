class Solution {
public:
    int squaredDistance(pair<int,int> p1, pair<int,int> p2) {
        int dx = p2.first - p1.first;
        int dy = p2.second - p1.second;
        return dx*dx + dy*dy;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        int q = queries.size();
        int n = points.size();

        for(int i=0; i < q; ++i){
            pair<int,int> center = {queries[i][0], queries[i][1]};
            int radiusSquared = queries[i][2] * queries[i][2];
            int cnt = 0;

            for(int j=0; j < n; ++j){
                pair<int,int> p = {points[j][0], points[j][1]};
                if (squaredDistance(center, p) <= radiusSquared)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
