#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
const i64 mod =  998244353;

vector<vector<i64>> dp(5e3 + 10,vector<i64>(5e3 + 10, 0));

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
	int n;
    cin >> n;
    for(int i = n; i > 0; i--) cout << dp[n][i] << " ";
    i64 ans = 0;
    for(int i = n; i > 0; i--) {
        ans = ans + (qmi(i, 3) * dp[n][i] % mod) % mod;
    }
    cout << "\n";
    cout << ans % mod << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 0; i <= 5e3; i++) {
        dp[i][i] = 1;
    }
    for(int i = 1; i <= 5e3; i++) {
        for(int j = 1; j < i; j++) {
            dp[i][j] = (i - 1) * (dp[i - 1][j]) + dp[i - 1][j - 1];
        }
        
    }
     
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}