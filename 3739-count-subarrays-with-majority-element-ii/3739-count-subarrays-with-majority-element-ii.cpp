class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<long long> freq(2 * n + 2, 0);
        vector<long long> acc(2 * n + 2, 0);

        freq[n + 1] = 1;
        acc[n + 1] = 1;

        int bal = n + 1;
        long long res = 0;

        for (int num : nums) {
            if (num == target)
                bal++;
            else
                bal--;

            freq[bal]++;
            acc[bal] = acc[bal - 1] + freq[bal];
            res += acc[bal - 1];
        }

        return res;
    }
};