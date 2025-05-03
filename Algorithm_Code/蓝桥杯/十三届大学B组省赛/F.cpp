#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n, m, k;
	cin >> n >> m >> k;
	i64 ans = 0;
	vector<vector<i64>> v(n + 1, vector<i64>(m + 1, 0));
	for(i64 i = 1; i <= n; i++) {
		for(i64 j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<i64>> pre(n + 1,vector<i64>(m + 1, 0));
	for(i64 i = 1; i <= n; i++) {
		for(i64 j = 1; j <= m; j++) {
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + v[i][j] - pre[i - 1][j - 1] ; 
			//cout << pre[i][j] << " ";
		}
		//cout << endl;
	}
	for(i64 i1 = 1; i1 <= n; i1++) {
		for(i64 j1 = 1; j1 <= m; j1++) {
			for(i64 i2 = i1; i2 <= n; i2++) {
				for(i64 j2 = j1; j2 <= m; j2++) {
					if(pre[i2][j2] - pre[i1 - 1][j2] - pre[i2][j1 - 1] + pre[i1 - 1][j1 - 1] <= k) {
						//cout << i1 << " " << j1 << " " << i2 << " " << j2 << " " << 
						//pre[i2][j2] - pre[i1 - 1][j2] - pre[i2][j1 - 1] + pre[i1 - 1][j1 - 1] << endl; 
						ans++;	
					}
				}
			}
		}
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