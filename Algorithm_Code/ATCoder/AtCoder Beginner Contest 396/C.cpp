#include<bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve()
{
	int n, m;
	cin >> n >> m;
	vector<i64> b(n);
	vector<i64> w(m);
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < m; i++) cin >> w[i];
	sort(b.begin(),b.end(),[&](const i64 &a, const i64 &b) -> bool {
	return a > b;} 
	);
	sort(w.begin(), w.end(),[&](const i64 &a, const i64 &b) -> bool {
	return a > b;} 
	);
	i64 ans = 0;
	i64 idx = n;
	for(int i = 0; i < n; i++) {
		if(b[i] >= 0) ans += b[i];
		else {
			idx = i;
			break;
		}  
	}
	for(int i = 0 ; i < m; i++) {
		if(i < idx) {
			if(w[i] >= 0) ans += w[i];
			else break;
		} else {
			if(i < n && w[i] + b[i] >= 0) ans += w[i] + b[i];
		}
	}
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
} 
