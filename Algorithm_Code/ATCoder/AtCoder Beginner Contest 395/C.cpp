#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	map<int,int> mp;
	int ans = 100000000;
	for(int i = 0; i < n; i++) {
		if(mp.count(a[i])) {
			ans = min(i - mp[a[i]] + 1, ans);
		}
		mp[a[i]] = i;
	}
	if(ans == 100000000) cout << -1;
	else cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}