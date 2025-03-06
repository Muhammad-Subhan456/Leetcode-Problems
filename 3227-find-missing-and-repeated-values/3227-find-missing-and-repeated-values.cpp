class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<int>freq((size*size)+1,0);
        vector<int>ans;
        for(int i=0; i < grid.size();i++){
            for(int j=0; j < grid.size(); j++){
                freq[grid[i][j]]++;
            }
        }
        for(int i=1; i < freq.size();i++){
            if(freq[i]>1)
                ans.push_back(i);
        }
         for(int i=1; i < freq.size();i++){
            if(freq[i]==0)
                ans.push_back(i);
        }
    return ans;
        
    }
};