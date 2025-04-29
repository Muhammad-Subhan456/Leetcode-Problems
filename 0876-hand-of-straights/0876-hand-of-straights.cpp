class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      if(hand.size()%groupSize!=0)
            return false;
        
        unordered_map<int,int> map;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto x:hand){
            map[x]++;
        }
        
        for(auto p:map){
            pq.push(p.first);
        }

        while(!pq.empty()) {
            int first = pq.top();
            for(int i=0;i<groupSize;i++) {
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