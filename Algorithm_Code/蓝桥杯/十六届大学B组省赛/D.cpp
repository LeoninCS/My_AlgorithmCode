#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;


void solve()
{
	int n, m;
	cin >> n >> m;
	vector<i64> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(),v.end());
	vector<i64> b;
	for(int i = 0; i < n - 1; i++) {
		i64 add = v[i + 1] * v[i + 1] - v[i] * v[i];
		b.push_back(add);
	}
	sort(b.begin(),b.end());
	i64 ans = 0;
	for(int i = 0; i < m - 1; i++) {
		ans += b[i];
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