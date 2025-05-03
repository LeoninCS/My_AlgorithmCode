#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

vector<i64> v;

void solve()
{
	i64 n = 0;
	cin >> n;
	i64 ans = 0;
	for(i64 i = 1; i < n; i++) {
		i64 add = i + (i * (i - 1)) / 2;
		if(add >= n) {
			ans = i;
			break;
		}
	}
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