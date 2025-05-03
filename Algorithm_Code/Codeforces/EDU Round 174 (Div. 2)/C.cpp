
#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	
	vector<int> f(n + 1, 0);
	int cnt = 0;
	int ans = 0;
	for(int i = 0 ;i < n; i++) {
		if(v[i] == 1) {
			f[i + 1] = f[i];
			cnt++;
		} else if(v[i] == 2) {
			f[i + 1] = ((f[i] * 2) % mod + cnt) % mod;
		} else {
			f[i + 1] = f[i];
			ans  = (ans + f[i]) % mod; 
		}
	}
	cout << ans << endl;
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

