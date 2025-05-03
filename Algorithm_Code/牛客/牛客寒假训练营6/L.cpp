#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int cnt[26];

void solve()
{
	memset(cnt, 0, sizeof(cnt));
	string tem = "CHICKEN";
	int n = 0;
	string s;
	cin >> n >> s;
	int idx = 0;
	for(int i = 0; i < n; i++) {
		if(idx < 7 && s[i] == tem[idx]) idx++;
		else cnt[s[i] - 'A']++;
	}
	int mx = 0;
	for(int i = 0; i < 26; i++) mx = max(mx, cnt[i]);
	if(idx == 7 && (n - 7) % 2 == 0 && mx * 2 - (n - 7) < 2) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}