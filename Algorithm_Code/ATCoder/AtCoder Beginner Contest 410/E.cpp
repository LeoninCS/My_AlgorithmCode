//dp降维

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(h + 1));
    for(int i = 0; i <= h; i++) dp[0][i] = m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= h; j++) {
            if(j >= a[i]) dp[i + 1][j] = max(dp[i][j - a[i]],dp[i][j] - b[i]); 
            else dp[i + 1][j] = dp[i][j] - b[i];
            if(dp[i + 1][j] >= 0) ans = i + 1;  
        }
    }
    cout << ans;
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