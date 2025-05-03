#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int n, m,s[500005];

int lowbit(int x) 
{
	return x & (-x);
}

void update(int x, int k)
{
	while(x <= n) s[x] += k, x += lowbit(x); 
}

int queary(int x)
{
	int t = 0;
	while(x) t += s[x], x -= lowbit(x);
	return t; 
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int val = 0;
		cin >> val;
		update(i, val);
	}
	for(int i = 0; i < m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		if(a == 1) update(b, c);
		else {
			int ans = queary(c) - queary(b - 1);
			cout << ans << endl;
		}
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