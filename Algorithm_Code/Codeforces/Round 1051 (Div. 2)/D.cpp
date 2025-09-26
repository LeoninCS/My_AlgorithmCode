#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 mod = 1e9 + 7;

void solve()
{ 
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    i64 ans = 0;
    //题目化简为不能有最长超过2的递减子序列
    vector<vector<int>> dp(301, vector<int>(301, 0)); //dp[i][j],i表示最大值，j表示次大值（i一定在j的前面）
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        auto tem = dp;
        for(int j = 0; j <= 300; j++) {
            for(int k = 0; k <= j; k++) {
                if(a[i] >= j) dp[a[i]][k] = (dp[a[i]][k] + tem[j][k]) % mod;
                else if(a[i] > k) dp[j][a[i]] = (dp[j][a[i]] + tem[j][k]) % mod;
            }
        }
    }
    for(int i = 0; i <= 300; i++) {
        for(int j = 0; j <= 300; j++) {
            ans += dp[i][j];
        }
    }
    cout << (ans % mod) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    
    return 0;
}
