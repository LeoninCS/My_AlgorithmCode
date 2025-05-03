#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 n , m;
	cin >> n >> m;
	vector<vector<i64>> v(n,vector<i64>(m));
	vector<vector<i64>> val(n,vector<i64>(m));
	for(int i =0 ; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
		for(int j = 0; j < m; j++) {
			cin >> val[i][j];
		}
	}
	i64 ans = 0;
	for(int i =0 ; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(v[i][j] == 7) ans += val[i][j] * 1;
			else if(v[i][j] == 77) ans += val[i][j] * 2;
			else if(v[i][j] == 777) ans += val[i][j] * 3;
		}
	}
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
