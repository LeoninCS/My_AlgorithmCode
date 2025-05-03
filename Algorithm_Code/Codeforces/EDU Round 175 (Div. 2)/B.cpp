#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 n, x, k;
	cin >> n >> x >> k;
	string s;
	cin >> s;
	i64 cntr = 0;
	i64 cntl = 0;
	i64 t = -1;
	for(i64 i = 0; i < n; i++) {
		if(s[i] == 'R') cntr++;
		else cntl++;
		if(cntr - cntl + x == 0) {
			t = i + 1;
			break;
		}
	}
	if(t == -1) {
		cout << 0 << endl;
		return;
	}
	k -= t;
	cntr = 0, cntl = 0;
	t = -1;
	for(i64 i = 0; i < n; i++) {
		if(s[i] == 'R') cntr++;
		else cntl++;
		if(cntr == cntl) {
			t = i + 1;
			break;
		}
	}
	if(t == -1) {
		cout << 1 << endl;
		return;
	}
	i64 ans = k / t + 1;
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

