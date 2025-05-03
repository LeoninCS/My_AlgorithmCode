#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
i64 mod = 1000000007;

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> f(n + 1, 0);
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2] + f[i - 3] * 2;
		f[i] %= mod;
	}	
	cout << f[n];
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