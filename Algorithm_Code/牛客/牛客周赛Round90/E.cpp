#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
	cin >> n;
	vector<i64> v(n);
	vector<int> cnt(n,0);
	i64 mi = INF;
	for(int i = 0; i < n; i++)  cin >> v[i];	
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cnt[a]++;
		cnt[b]++;
	}
	i64 ans = 0;
	int cot = 0;
	for(int i = 0; i < n; i++) {
		if(cnt[i] <= 1) {
			ans += v[i];
			cot++;	
		} 
		mi = min(mi, v[i]);
	} 
	if(cot % 2 == 1) ans += mi;
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