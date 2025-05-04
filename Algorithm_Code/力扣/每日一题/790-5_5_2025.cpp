/*
class Solution {
public:
    int numTilings(int n) {
        vector<vector<long long>> dp(n + 1,vector<long long>(4));
        dp[1][0] = 1;
        dp[1][1] = 0;
        dp[1][2] = 0;
        dp[1][3] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = dp[i - 1][2] + dp[i - 1][0];
            dp[i][2] = dp[i - 1][1] + dp[i - 1][0];
            dp[i][3] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][0];
            dp[i][0] %= (long long)(1e9 + 7);
            dp[i][1] %= (long long)(1e9 + 7);
            dp[i][2] %= (long long)(1e9 + 7);
            dp[i][3] %= (long long)(1e9 + 7);
        }
        return dp[n][3];
    }
};
*/