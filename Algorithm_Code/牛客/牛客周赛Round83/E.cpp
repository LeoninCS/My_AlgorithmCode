#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n , k;
	cin >> n >> k;
	vector<i64> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<i64>> f(n + 1,vector<i64>(k + 1,-1e18));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			for(int z = 1; z <= min(i,6); z++) {
				f[i][j] = max(f[i][j], f[i - z][j - 1] + a[i - 1]);
			}
		}
	}
	i64 ans = LLONG_MIN;
	for(int i = 1; i <= n; i++) ans = max(ans,f[i][k]);
	cout << ans << endl;
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