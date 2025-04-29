class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
       if(nums.size()%k!=0)
            return false;
        
        unordered_map<int,int> map;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto x:nums){
            map[x]++;
        }
        
        for(auto p:map){
            pq.push(p.first);
        }

        while(!pq.empty()) {
            int first = pq.top();
            for(int i=0;i<k;i++) {
                if(map.find(first+i)==map.end()) {
                    return 0;
                }

                map[first+i]--;
                if(map[first+i]==0) {
                    if(first+i != pq.top()) {
                        return 0;
                    }
                    pq.pop();
                }
            }
        }
        return 1;

       


    }
};