#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n;
	cin >> n;
	vector<i64> w(n);
	vector<i64> m(n);
	for(int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> m[i];
	}
	sort(w.begin(),w.end(),[&](const i64& a, const i64 &b) -> bool {
		return a < b;
	}
	);
	sort(m.begin(),m.end(),[&](const i64& a, const i64 &b) -> bool {
		return a > b;
	}
	);
	i64 ans = 0;
	for(int i = 0; i < n; i++) {
		cout << w[i] << " " << m[i] << endl;
		ans += w[i]*m[i];
	}
	//cout << ans;
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
