#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;
i64 mod = 998244353;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<vector<i64>> dp(n, vector<i64>(2));
    dp[0][0] = 1, dp[0][1] = 1;
    for(int i = 1; i < n; i++) {
        if(min(a[i], b[i]) >= max(a[i - 1], b[i - 1])) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        } else if(max(a[i], b[i]) < max(a[i - 1], b[i - 1]) || min(a[i], b[i]) < min(a[i - 1], b[i - 1])) {
            dp[i][0] = 0;
            dp[i][1] = 0;
        } else {
            if(a[i] >= a[i - 1]) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            } else {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0];
            }
        }
        dp[i][0] = dp[i][0] % mod;
        dp[i][1] = dp[i][1] % mod;
    }
    int ans = (dp[n - 1][0] + dp[n - 1][1]) % mod;
    cout << ans << "\n"; 
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