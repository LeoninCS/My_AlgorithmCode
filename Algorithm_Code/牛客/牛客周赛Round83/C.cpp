#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 x = 0;
	cin >> x;
	int cnt = 0;
	while(x) {
		cnt++;
		x /= 10;
	}
	cout << 1;
	for(int i = 1; i < cnt; i++) cout << 0;
	cout << 1 << endl;
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