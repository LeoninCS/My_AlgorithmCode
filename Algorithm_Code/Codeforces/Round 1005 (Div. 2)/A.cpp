#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	string s;
	cin >> n >>s;
	int cnt0 = 0;
	int cnt1 = 0;
	for(int i = 0; i < n; i++) {
		if(i > 0 && s[i] == s[i - 1]) continue;
		if(s[i] == '1') cnt1++;
	}
	if(s[n - 1] == '1') cout << 2 * cnt1 - 1;
	else cout << 2 * cnt1;
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