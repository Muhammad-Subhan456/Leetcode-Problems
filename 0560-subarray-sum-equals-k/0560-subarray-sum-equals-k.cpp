class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]= 1;
        int cnt=0,pre=0;
        for(int i=0; i < nums.size(); ++i){
            pre += nums[i];
            int remove = pre-k;
            cnt += m[remove];
            m[pre]++;
        }

        return cnt;
    }
};