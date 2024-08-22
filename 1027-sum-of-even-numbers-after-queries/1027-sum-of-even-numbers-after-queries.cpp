class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0; i < queries.size();++i){
        int sum=0;
            nums[queries[i][1]] += queries[i][0];
            for(int j=0; j < nums.size();++j){
                if(nums[j]%2==0)
                    sum+=nums[j];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};