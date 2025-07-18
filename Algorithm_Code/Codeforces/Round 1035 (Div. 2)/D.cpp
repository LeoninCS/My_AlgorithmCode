#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;



void solve()
{ 
    i64 n, m;
    cin >> n >> m;
    
    vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, 0));
    
    dp[n][0] = 1;
    dp[n][1] = n;

    for(int i = n - 1; i >= 1; i--) {
        for(int j = 0; j < n - i + 1; j++) {
            dp[i][j] = (dp[i][j] + dp[i + 1][j]) % m;
            dp[i][j + 1] = (dp[i][j + 1] + dp[i + 1][j] * (n - i + 1 - j) * i) % m;
        }
    }

    i64 ans = 0;
    for(int i = 0; i <= n; i++) ans = (ans + dp[1][i]) % m ;
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