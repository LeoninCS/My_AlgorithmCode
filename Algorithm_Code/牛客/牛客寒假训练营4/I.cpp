#include<bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	int n = 0;
	cin >> n >> s;
	string tem = "uwawauwa";
	int cnt = 0,ans = 0;
	for(int i = 0; i < n - 7; i++) {
		string sub = s.substr(i, 8);
		if(sub == tem) ans += cnt;
		if(i > 0 && s[i - 1] == 'u') cnt++;
	}
	
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