#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	bool ans = true;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a == 1) ans = false;
	}
	if(ans) cout << -1 << endl;
	else cout << 999999999999999989 << endl;
}


int main()
{
	int T;
	cin >> T;
	
	while(T--) solve();
	
	return 0;
}
