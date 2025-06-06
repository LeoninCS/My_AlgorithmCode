/*
//动态规划+状态压缩
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<vector<int>> dp(k,vector<int>(1 << n));
        for(int i = 0; i < k; i++) {
            for(int j = 0; j <= 1 << n; j++) {
                for(int k = 0; k < n; k++) {
                    dp[i][j] = min(dp[i][j],dp[i][j + 1 << k] + jobs[k]);
                }
            }
        }
        return dp[1 << n - 1];
    }
};
*/