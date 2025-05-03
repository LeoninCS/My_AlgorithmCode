#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
	int n,m;
	string s1,s2;
	cin >> n >> m >> s1 >> s2;
	
	int cnt1[26],cnt2[26];
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	for(int i = 0; i < n; i++) {
		cnt1[s1[i] - 'a']++;
	}
	for(int i = 0; i < m; i++) {
		cnt2[s2[i] - 'a']++;
	}
	
	for(int i = 0; i < 26; i++) {
		if(cnt1[i] <= cnt2[i]) {
			n -= cnt1[i];
			m -= cnt1[i];
			cnt2[i] -= cnt1[i];
			cnt1[i] -= cnt1[i];
		}
		else {
			n -= cnt2[i];
			m -= cnt2[i];
			cnt1[i] -= cnt2[i];
			cnt2[i] -= cnt2[i];
		}
	}
	
	int mul = abs(n - m);
	mul /= 2;
	mul *= 2;
	int ans = 0;
	if(n > m) {
		int mx = 0;
		for(int i = 0; i < 26; i++) {
			cnt1[i] /= 2;
			cnt1[i] *= 2;
			mx += cnt1[i];
		}
		ans = m + max(0, mul - mx) / 2;
	} 
	else if(n < m) {
		int mx = 0;
		for(int i = 0; i < 26; i++) {
			cnt2[i] /= 2;
			cnt2[i] *= 2;
			mx += cnt2[i];
		}
		ans = n + max(0, mul - mx) / 2;
	}
	else {
		ans = n;	
	}
	
	//cout << n << " " << m << endl;
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