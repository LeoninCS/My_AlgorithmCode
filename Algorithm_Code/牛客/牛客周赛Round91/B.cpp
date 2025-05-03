#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n = 0;
	cin >> n;
	vector<i64> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	i64 ans = 0;
	i64 cur = 0;
	for(int i = 0; i < min(n,10); i++) {
		cur += v[i];
	}
	ans = cur;
	if(n <= 10) {
		cout << ans;
	} else {
		for(int i = 10; i < n; i++) {
			cur += v[i];
			cur -= v[i - 10];
			ans = max(ans,cur);
		}
		cout << ans;
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