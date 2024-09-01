class Solution {
private:
    int largestRectangleArea(vector<int>& heights, int n) {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        int area = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int l = heights[i];
            if (next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            int new_area = l * b;
            area = max(area, new_area);
        }
        return area;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int max_area = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            max_area = max(max_area, largestRectangleArea(heights, m));
        }
        return max_area;
    }
};
