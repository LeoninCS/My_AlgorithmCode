#include<bits/stdc++.h>
using namespace std;


void solve()
{
	int n = 0;
	cin >> n;
	int ans = n % 15;
	if(ans > 2) ans = 2;
	n /= 15;
	ans += 3 * n;
	cout << ans + 1<< endl;
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

