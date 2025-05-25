/*
//简单构造
class Solution {
public:
      long long minCuttingCost(int n, int m, int k) {
        n = max(n,m);
        long long ans = (long long) k * (long long) (n - k);
        ans = max(0LL,ans);
        return ans;
    }
};
*/