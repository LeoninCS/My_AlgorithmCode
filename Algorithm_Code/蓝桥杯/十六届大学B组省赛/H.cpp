#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
i64 mod = 1e9 + 7;

i64 qmi(i64 a, i64 b)
{
	if(b < 0) return 0;
	i64 c = 1;
	while(b) {
		if(b % 2 == 1) c = c * a % mod;
		a = a * a % mod; 
		b /= 2;
	}
	return c % mod;
}


void solve()
{
	i64 n = 0;
	cin >> n;
	i64 ans = 0;
	i64 cur = 0;
	for(int i = 0; i < n; i++) {
		i64 val = 0;
		cin >> val;
		cur ^= val;
		i64 c = qmi(3, n - 2 - i) * 2;
		ans += max(c , (i64)1) * cur;
		ans %= mod;
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