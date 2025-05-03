#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k,p;
	cin >> n >> k >> p;
	k = abs(k);
	int ans = k / p + (k % p > 0);
	//cout << ans << endl;
	if(ans <= n) cout << ans << endl;
	else cout << -1 << endl;
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