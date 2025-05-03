#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve()
{
	int k = 0;
	cin >> k;
	if(k % 3 == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
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