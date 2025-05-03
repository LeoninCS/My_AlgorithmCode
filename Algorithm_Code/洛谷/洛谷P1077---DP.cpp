#include<bits/stdc++.h>
using namespace std;

const int mod = 1e6 + 7;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	//input
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> f(n + 1,vector<int>(m + 1,0));
	//DP
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= min(j, a[i - 1]); k++)
			f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
		}
	}
	cout << f[n][m];
	return 0;
}
