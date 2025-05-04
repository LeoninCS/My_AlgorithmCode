#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<i64> c(n + 1, 0);
    vector<int> a(n + 1, 0);
    for(int i = 1; i < n; i++) cin >> c[i];
    for(int i = 1; i < n; i++) cin >> a[i];
    c[n] = n;
    a[n] = 1;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n + 1; j++) {
            if(j - c[j] <= i) dp[j] = min(dp[i] + 1, dp[j]);
            if(a[j] == 1) break;
        }
        //cout << dp[i] << " ";
    }

    cout << dp[n] - 1 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}