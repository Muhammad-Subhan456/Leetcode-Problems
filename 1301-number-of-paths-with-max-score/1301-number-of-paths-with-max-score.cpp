class Solution {
public:
const int INF = 1e9;
const int MOD = 1e9+7;
    struct Node {
    int score;
    int ways;
};
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size(), m = b[0].size();
        vector<vector<Node>> dp(n, vector<Node>(m, {-2, 0}));
        function<Node(int,int)> rec = [&](int i,int j) -> Node{
            if(i < 0 || j < 0) return {-INF,0};
            if(b[i][j] == 'X') return {-INF,0};
            if(i==0 && j==0 ) return {0,1};
            if(dp[i][j].score != -2) return dp[i][j];
            Node a = rec(i-1,j);
            Node b1 = rec(i,j-1);
            Node c = rec(i-1,j-1);
            int best = max({a.score,b1.score,c.score});
            if(best < 0) return dp[i][j] = {-INF,0};
            long long ways = 0;
            if(a.score == best) ways += a.ways;
            if(b1.score == best) ways += b1.ways;
            if(c.score == best) ways += c.ways;
            ways %= MOD;
            int val = 0;
            if(b[i][j] != 'S' && b[i][j] != 'E' ) val = b[i][j] - '0';
            return dp[i][j] = {best+val,(int)ways};
        };
        Node ans = rec(n-1,m-1);
        if(ans.ways == 0) return {0,0};
        return {ans.score,ans.ways};
    }
};