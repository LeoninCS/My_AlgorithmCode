#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n = 0;
	cin >> n;
	vector<i64> a(n);
	vector<i64> b(n / 2);
	for(i64 i = 0; i < n; i++) cin >> a[i];
	for(i64 i = 0; i < n / 2; i++) {
		b[i] = a[n - 1 - i] - a[i];
	}	
	i64 ans = 0;
	for(i64 i = 0; i < n / 2 - 1; i++) {
		ans += abs(b[i]);
		if(b[i] < 0 && b[i + 1] < 0) b[i + 1] = min(b[i + 1] - b[i], (i64)0);
		if(b[i] > 0 && b[i + 1] > 0) b[i + 1] = max(b[i + 1] - b[i], (i64)0);
	}
	ans += abs(b[n / 2 - 1]);
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