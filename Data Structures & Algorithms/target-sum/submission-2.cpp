class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(begin(nums), end(nums), 0);
        if (abs(target) > total_sum || ((target + total_sum) % 2 != 0)) return 0;
        int total = (total_sum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= total; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][total];
    }
};
