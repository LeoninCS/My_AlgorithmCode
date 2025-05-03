#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 x , y;
	cin >> x >> y;
	x += (x + 1);
	if(x % 4 == y % 4) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}