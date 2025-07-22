
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
const i64 mod = 998244353;
const i64 inv2 = (mod + 1) / 2;
void solve()
{
	i64 n;
    cin >> n;
    i64 ans = (n % mod * ((n + 1) % mod) % mod * inv2) % mod;
	for(i64 i = 1; i <= n; i++) {
		i64 div = n / i;
		i64 nxt = n / div;
		ans = (ans + mod - ((nxt - i + 1) % mod * (div % mod)) % mod) % mod;
		i = nxt; 
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