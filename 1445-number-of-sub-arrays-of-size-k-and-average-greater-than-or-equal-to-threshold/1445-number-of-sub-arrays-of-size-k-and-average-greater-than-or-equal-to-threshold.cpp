class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, r = k - 1, sum = 0, cnt = 0;
        int n = arr.size();
        for (int i = 0; i <= r; ++i) {
            sum += arr[i];
        }
        while (r < n-1) {
            if (sum / k >= threshold)
                cnt++;
            sum -= arr[l]; 
            l++;
            r++;
            sum += arr[r];
        }
        if (sum / k >= threshold)
                cnt++;
        return cnt;
    }
};