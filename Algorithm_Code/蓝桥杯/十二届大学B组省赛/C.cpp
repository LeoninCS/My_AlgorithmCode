#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

vector<i64> v;

void solve()
{
	int n = 20, m = 21;
	int ans = (n * m) * (n * m - 1) / 2;
	for(int i = 2; i <= n; i++) {
		int mul = i * (i - 1) / 2 - 1;
		ans -= 4 * mul; 
	}
	int muln = n * (n - 1) / 2 - 1;
	int mulm = m * (m - 1) / 2 - 1;
	ans -= m * muln;
	ans -= n * mulm;
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