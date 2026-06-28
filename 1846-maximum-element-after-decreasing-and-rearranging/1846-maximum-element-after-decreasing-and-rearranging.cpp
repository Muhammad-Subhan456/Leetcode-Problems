class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int k = 1, n = arr.size();
        if (arr[0] != 1)
            arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] > 1) {
                if (arr[i - 1] + 1 <= arr[i])
                    arr[i] = arr[i - 1] + 1;
                else
                    arr[i] = arr[i - 1] - 1;
            }
        }
        return arr[n - 1];
    }
};