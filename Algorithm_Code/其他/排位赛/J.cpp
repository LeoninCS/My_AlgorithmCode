#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;



void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> pre(5000,vector<int>(n + 1, 0));
	for(int i = 0; i <= 5000; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j - 1] <= i) cnt++;
			pre[i][j] = cnt;
		}
	}
	while(q--) {
		int l, r , k;
		cin >> l >> r >> k;
		int ans = pre[k][r] - pre[k][l - 1];
		cout << ans << endl;
	}
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