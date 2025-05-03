#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 n , m, k;
	cin >> n >> m >> k;
	i64 mx = 0;
	for(i64 i = 0; i < k; i++) {
		i64 v = 0;
		cin >> v;
		mx = max(mx, v); 
	}
	i64 ans = n * (mx - m);
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
} 
