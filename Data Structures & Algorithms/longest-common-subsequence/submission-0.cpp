class Solution {
   public:
    int longestCommonSubsequence(string x, string y) {
        int n = x.size();
        int m = y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // jo ye maine yaha 0 initialize kiya hai actyualy base condition par kiya hai muajhe sirf
        // 1row aur 1 col ko hiu karn atha but but the main thing is i hav eputted the whole matrix
        // as 0 so that
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
