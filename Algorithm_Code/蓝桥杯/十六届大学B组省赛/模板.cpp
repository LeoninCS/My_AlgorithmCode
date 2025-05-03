#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int ans = 0;
void solve()
{
	int a = 0;
	cin >> a;
	if(a != 1) ans++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;
	while(T--) solve();
	cout << ans;
	return 0;
}