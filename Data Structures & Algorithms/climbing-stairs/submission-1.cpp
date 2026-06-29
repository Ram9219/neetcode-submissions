#include<bits/stdc++.h>
class Solution {
public:
    int dp[10001];

    int solve(int n) {
        if (n == 0 || n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1) + solve(n - 2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};