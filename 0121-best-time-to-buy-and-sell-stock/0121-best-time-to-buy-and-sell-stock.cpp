class Solution {
public:
    int maxProfit(vector<int>& prices) {
    if(prices.size()==1) return 0;
    int mini = prices[0];
    int maxi = INT_MIN;
    for(int i=1; i < prices.size(); ++i){
        mini = min(mini,prices[i]);
        maxi = max(maxi,prices[i]-mini);
    } 
    return maxi;   
    
    }
};