#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int n, m, arr[500005],s[500005];

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
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if(a == 1) {
			int b,c,d;
			cin >> b >> c >> d;
			update(b, d);
			update(c + 1, -d);
		} else {
			int b;
			cin >> b;
			int ans = arr[b] + queary(b);
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