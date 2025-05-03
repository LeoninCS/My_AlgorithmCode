#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
	int n = 0;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	n /= 2;
	int l_mid = a[(n - 1) / 2];
	int r_mid = a[n + (n - 1) / 2];
	ll l_l = 0, l_m = 0, l_r = 0;
	for(int i = 0; i < n; ++i) {
		l_l += abs(l_mid - 1 - a[i]);
		l_m += abs(l_mid - a[i]);
		l_r += abs(l_mid + 1 - a[i]);
	}
	ll r_l = 0, r_m = 0, r_r = 0;
	for(int i = n; i < 2 * n; ++i) {
		r_l += abs(r_mid - 1 - a[i]);
		r_m += abs(r_mid - a[i]);
		r_r += abs(r_mid + 1 - a[i]);
	}
	ll ans = 0;
	if(l_mid == r_mid) ans = min(l_m + (min(r_l, r_r)),min(l_l, l_r) + r_m);
	else ans = (l_m + r_m); 
	cout << ans << endl;
}

int main()
{
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
