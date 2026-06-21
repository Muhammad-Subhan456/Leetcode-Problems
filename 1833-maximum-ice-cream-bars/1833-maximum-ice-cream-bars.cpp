class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int check = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); ++i) {
            if (check + costs[i] > coins)
                return i;
            check += costs[i];
        }
        return costs.size();
    }
};