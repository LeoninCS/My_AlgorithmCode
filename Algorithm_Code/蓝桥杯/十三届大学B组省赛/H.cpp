#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 2, vector<int>(m + 2, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> v[i][j]; 
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(v[i][j] == 1) {
				cout << 9 << " ";
				continue;
			} 
			int cnt = 0;
			if(v[i - 1][j - 1] == 1) cnt++;
			if(v[i - 1][j] == 1) cnt++;
			if(v[i - 1][j + 1] == 1) cnt++;
			if(v[i][j - 1] == 1) cnt++;
			if(v[i][j + 1] == 1) cnt++;
			if(v[i + 1][j - 1] == 1) cnt++;
			if(v[i + 1][j] == 1) cnt++;
			if(v[i + 1][j + 1] == 1) cnt++;
			cout << cnt << " ";
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
	
	return 0;
}