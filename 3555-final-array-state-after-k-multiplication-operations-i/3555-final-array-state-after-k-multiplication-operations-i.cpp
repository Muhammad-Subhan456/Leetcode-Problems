class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i=0 ; i < nums.size(); ++i){
        pq.push({nums[i],i});
    }

    for(int i=0; i < k; ++i){
        pair<int,int>top = pq.top();
        pq.pop();
        int ans = top.first*multiplier;
        pq.push({ans,top.second});
        nums[top.second] = ans;
    }

    // while(!pq.empty()){
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }
    return nums;


    }
};