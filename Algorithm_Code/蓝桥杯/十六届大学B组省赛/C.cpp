#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;


void solve()
{
	i64 a, b, c , k;
	cin >> a >> b >> c >> k;
	while(k--) {
		i64 aa = (b + c) / 2;
		i64 bb = (a + c) / 2;
		i64 cc = (a + b) / 2;
		a = aa;
		b = bb;
		c = cc;
		if(a == b && b == c) break;
	}
	cout << a << " " << b << " " << c << endl;
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