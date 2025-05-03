#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		if(i % 2 == 0) cout  << 1 << " ";
		else cout << 2 << " ";	
	}
	cout << endl;
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