#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
	int n = 0;
	string s;
	cin >> n >> s;
	i64 cnt = 0;
	i64 cntm = 0;
	for(int i = 0; i < n ; i++) {
		if(s[i] == '-') cnt++;
		if(s[i] == '_') cntm++;
	}
	i64 ans = cntm * (cnt / 2) * (cnt / 2 + ((cnt % 2) > 0));
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