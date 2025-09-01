#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
	cin >> n;
	vector<i64> a(n);
	i64 sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	vector<vector<int>> dp(n + 1,vector<int>(2));
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++) {

	}
	int q;
	cin >> q;
	
	while(q--) {

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