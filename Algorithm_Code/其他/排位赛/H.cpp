#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;



void solve()
{
	int n,k;
	cin >> n >> k;
	vector<i64> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	vector<i64> pre(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i - 1];
	} 
	auto cal = [&](int idx) {
		i64 res = 0;
		int cnt = idx / n;
		int mod = idx % n;
		i64 res1 = pre[n] * (cnt + 1) * cnt / 2;
		i64 res2 = 0;
		for(int i = 0; i < mod; i++) {
			res2 += (cnt + 1) * a[i];
		}
		res = res1 + res2;
		return res;
	};
	int l, r;
	cin >> l >> r;
	i64 ans = cal(r) - cal(l - 1);
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