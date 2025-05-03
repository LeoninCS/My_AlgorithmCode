#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	vector<int> pre(n + 1, 0);
	vector<int> aft(n + 2, 0);
	int idx = 0;
	for(int i = 1; i <= n; i++) {
		if(idx >= m) {
			pre[i] = m;
			continue;
		}
		if(a[i - 1] >= b[idx]) idx++;
		pre[i] = idx;
	}
	idx = m - 1;
	for(int i = n; i >= 1; i--) {
		if(idx < 0) {
			aft[i] = m;
			continue;
		}
		if(a[i - 1] >= b[idx]) idx--;
		aft[i] = m - 1 - idx;
	}
	int ans = inf;
	for(int i = 0; i <= n; i++) {
		if(pre[i] + aft[i + 1] == m - 1) ans = min(ans,b[pre[i]]);
		if(pre[i] + aft[i + 1] == m) ans = 0;
	}
	if(ans == inf) cout << -1 << endl;
	else cout << ans << endl;
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