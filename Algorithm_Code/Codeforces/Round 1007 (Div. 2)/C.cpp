#include<bits/stdc++.h>
using namespace std;
using i64 = long long;



void solve()
{
	int n,st,en;
	cin >> n >> st >> en;
	vector<vector<int>> tree(n + 1);
	vector<int> vis(n + 1,0);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[b].push_back(a);
		tree[a].push_back(b);
	}
	auto dfs = [&](int root,auto&& dfs) -> void {
		for(auto nxt: tree[root]) {
			if(!vis[nxt]) {
				vis[nxt] = 1;
				dfs(nxt,dfs);
			}
		}
		cout << root << " ";
	};
	vis[en] = 1;
	dfs(en,dfs);
	cout << endl;
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
/*
1
7 1 1
1 2
1 3
2 4
2 5
3 6
3 7
*/