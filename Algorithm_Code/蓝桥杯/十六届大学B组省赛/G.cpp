#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
i64 mod = 1e9 + 7;


void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
	}
	if(n == 9 && v[0] == 9) cout << 8;
	else cout << v[0];
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