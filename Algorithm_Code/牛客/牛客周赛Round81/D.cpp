#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> v(n,vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		sort(v[i].begin(),v[i].end());
	}
	int ans = 1;
	for(int i = 1; i < n; i++) {
		int idx = 0;
		for(int j = 0; j < n; j++) {
			if((idx == 0 && v[i][j] >= v[i - 1][idx]) || (idx == i && v[i][j] >= v[i][idx - 1] ) ||(idx > 0 && v[i][j] >= v[i - 1][idx - 1] && v[i][j] >= v[i - 1][idx])) {
				swap(v[i][idx],v[i][j]);
				idx++;
			}
			if(idx > i) {
				ans++; 
				break;
			}
		}
		if(idx <= i) break;
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