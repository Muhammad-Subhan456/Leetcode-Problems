class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans;
        int obsum=0,sum=0;
        for(auto ele : rolls)
            obsum+=ele;
        sum = mean*(n+rolls.size());
        int remain_sum = sum - obsum;
        if(n*6 < remain_sum || remain_sum<n)
            return {};
        else{
            while(n){
                int div = remain_sum/n--;
                ans.push_back(div);
                remain_sum -=div;
            }
        }
        return ans;
    }
};