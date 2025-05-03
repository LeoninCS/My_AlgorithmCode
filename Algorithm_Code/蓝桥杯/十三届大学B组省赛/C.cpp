#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 a,b,n;
	cin >> a >> b >> n;
	i64 ans = 0;
	i64 seven = a * 5 + b * 2;
	ans += (n / seven) * 7;
	n %= seven;
	for(int i = 1;  n > 0 && i <= 5; i++) {
		ans++;
		n -= a;
	}
	for(int i = 1; n > 0 && i <= 2; i++) {
		ans++;
		n -= b;
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