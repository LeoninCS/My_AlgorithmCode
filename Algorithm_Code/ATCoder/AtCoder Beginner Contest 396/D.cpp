#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 INF = 1e18;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> gra(n);
	vector<vector<i64>> val(n, vector<i64>(n, 0));
	for(int i = 0; i < m; i++) {
		int a, b;
		i64 c;
		cin >> a >> b >> c;
		a--; b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
		val[a][b] = c;
		val[b][a] = c;
		
	}
	vector<int> vis(n);
	i64 ans = LLONG_MAX;
	auto dfs = [&](int cur,i64 sum, auto && dfs) -> void {
		if(cur == n - 1) ans = min(ans, sum);
		for(auto &nxt: gra[cur]) {
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			dfs(nxt, sum ^ val[cur][nxt], dfs);
			vis[nxt] = 0;
		}
	};
	vis[0] = 1;
	dfs(0 , 0, dfs);
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
