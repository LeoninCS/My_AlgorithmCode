#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
const long long INF = 1e18;


void solve()
{
	int n = 0;
	cin >> n;
	vector<string> g(n);
	for(int i = 0; i < n; i++) cin >> g[i];
	vector<vector<int>> dis(n, vector<int>(n, inf));
	queue<pair<int,int>> q;
	for(int i = 0 ; i < n; i++) {
		dis[i][i] = 0;
		q.push({i,i});
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j || g[i][j] == '-') continue;
			dis[i][j] = 1;
			q.push({i,j});
		}
	}
	
	while(!q.empty()) {
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(g[i][u] == g[v][j] && g[i][u] != '-' && dis[i][j] > dis[u][v] + 2) {
					dis[i][j] = dis[u][v] + 2;
					q.push({i,j});
				}  
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(dis[i][j] >= inf) cout << -1 << " ";
			else cout << dis[i][j] << " ";
		}
		cout << endl;
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}