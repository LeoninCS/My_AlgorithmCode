//图转树
#include<bits/stdc++.h>
#include <numeric>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, q;
    cin >> n >> q;
    vector<int> col(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> col[i];
	}
	vector<map<int,i64>> gra(n + 1);
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		gra[u][v] = w;
		gra[v][u] = w;
	}
	vector<int> pa(n + 1);
	vector<map<int,i64>> son(n + 1);
	i64 sum = 0, ans = 0;
	auto dfs = [&](auto & dfs, int u) -> void {
		for(auto [nxt,val] : gra[u]) {
			if(pa[u] == nxt) continue;
			pa[nxt] = u;
			son[u][col[nxt]] += val;
			sum += val;
			dfs(dfs, nxt);
		}
		ans += son[u][col[u]];
	};
	dfs(dfs,1);
	while(q--) {
		int u, x;
		cin >> u >> x;
		
		ans -= son[u][col[u]];
		if(col[u] == col[pa[u]]) {
			ans -= gra[pa[u]][u];
		}
		son[pa[u]][col[u]] -= gra[pa[u]][u];
		
		col[u] = x;
		
		ans += son[u][col[u]];
		if(col[u] == col[pa[u]]) {
			ans += gra[pa[u]][u];
		}  
		son[pa[u]][col[u]] += gra[pa[u]][u];
		cout << sum - ans << "\n";
	}
	
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