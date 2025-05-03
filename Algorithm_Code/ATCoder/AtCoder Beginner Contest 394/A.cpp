#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '2') cnt++;
	}
	for(int i = 1; i <= cnt; i++) cout << 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
}