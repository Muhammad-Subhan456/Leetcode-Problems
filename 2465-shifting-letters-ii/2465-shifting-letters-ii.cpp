class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> freq(n + 1, 0);
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int delta = (direction == 1) ? 1 : -1;
            freq[start] += delta;
            freq[end + 1] -= delta; 
        }
        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift += freq[i];
            int new_char = ((s[i] - 'a' + shift) % 26 + 26) % 26;
            s[i] = 'a' + new_char;
        }

        return s;
    }
};
