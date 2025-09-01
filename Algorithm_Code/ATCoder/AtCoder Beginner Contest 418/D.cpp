#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    string t;
    cin >> n >> t;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    i64 ans = 0;
    for(int i = 1; i <= n; i++) {
        if(t[i - 1] == '0') {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][0];
        } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + 1;
        }
        ans += dp[i][1];
    }
    
    cout << ans << "\n";
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