#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	string tem = "while";
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < 5; i++) {
		if(s[i] != tem[i]) ans++;
	}	
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}