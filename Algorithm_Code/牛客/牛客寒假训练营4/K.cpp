#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int a,b,c,A,B,C;
	cin >> a >> b >> c >> A >> B >> C;
	int ans = max({a*A, b*B, c*C});
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