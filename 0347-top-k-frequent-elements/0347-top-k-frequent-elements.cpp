class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int>m;
      priority_queue<pair<int, int>> q;
      vector<int>ans;
      for(auto c : nums) m[c]++;

      for(auto p : m){
        q.push({p.second,p.first});
      }
      while(k--) {
      ans.push_back(q.top().second);
        q.pop();
      }
      return ans;

    }
};