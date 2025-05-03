#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<i64> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<i64> pre(n + 1, 0);
	vector<i64> aft(n + 2, 0);
	for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + max((i64)0, v[i]);
	for(int i = n; i >= 1; i--) aft[i] = aft[i + 1] + min((i64)0,v[i - 1]);
	i64 ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, pre[i] - aft[i]);
	cout << ans << endl;
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