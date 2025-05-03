#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
	int n = 0;
	cin >> n;
	vector<ll> a(n);
	ll ans = 0;
	ll sum = 0;
	for(ll i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		ans += (i+1);
	}
	if(sum != ans) {
		cout << -1;
		return;
	}
	sort(a.begin(),a.end());
	ans = 0;
	for(ll i = 0; i < n; ++i) {
		ans += abs((i + 1) - a[i]);
	}
	cout << ans / 2;
}


int main()
{
	int T = 1;
	while(T--) solve();
	
	return 0;
}
