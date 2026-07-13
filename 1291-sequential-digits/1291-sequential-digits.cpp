class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> res;

        for (int k = 2; k <= 9; k++) {
            int l = 0, r = k - 1;
            string t;

            for (int i = l; i <= r; i++)
                t += s[i];

            while (true) {
                int num = stoi(t);
                if (num >= low && num <= high)
                    res.push_back(num);

                if (r == 8) break;

                l++;
                r++;
                t.erase(t.begin());
                t += s[r];
            }
        }

        return res;
    }
};