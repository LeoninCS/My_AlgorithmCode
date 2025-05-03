#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,m;
	cin >> n >> m;
	
	vector<vector<i64>> graph(n,vector<i64>(m));
	vector<i64> ltor(n + m);
	vector<i64> rtol(n + m);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> graph[i][j];
			ltor[j + i] += graph[i][j];
			rtol[j - i + n] += graph[i][j];
		}
	}
	
	i64 ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ans = max(ltor[j + i] + rtol[j - i + n] - graph[i][j], ans);
		}
	}
	
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