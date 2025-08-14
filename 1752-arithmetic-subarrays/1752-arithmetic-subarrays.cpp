class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& n, vector<int>& l, vector<int>& r) {
        vector<bool> v(l.size(), true);
        
        for (int i = 0; i < l.size(); ++i) {
            vector<int> temp(n.begin() + l[i], n.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            
            int dif = temp[1] - temp[0];
            for (int j = 1; j < temp.size(); ++j) {
                if (temp[j] - temp[j - 1] != dif) {
                    v[i] = false;
                    break;
                }
            }
        }
        
        return v;
    }
};
