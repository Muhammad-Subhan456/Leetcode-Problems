class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int ans = 0;
        int n = cost.size();
        for(int i = 0; i < n; ++i){
            if(i % 3 == 2) continue;
            ans += cost[i];
        }
        return ans;
    }
};