#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<i64>> dp(n + 1,vector<i64>(3, 0));
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] == 0) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][1];
        }
        if(a[i - 1] == 1) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1]);
        }
        if(a[i - 1] == -1) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1 + dp[i - 1][1]; 
        }
        dp[i][2] = dp[i][0] + dp[i][1];
    }
    for(int i = 0; i <= n; i++) {
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2]  << "\n";
    }
    cout << dp[n][2] << "\n";
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