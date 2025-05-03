#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> a(n,vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j <= i; j++) {
			if(a[i + 1][j] < a[i][j] || a[i + 1][j + 1] < a[i][j]) {
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
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