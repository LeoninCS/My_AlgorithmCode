#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> cur(n + 1); 
	vector<pair<int,int>> paa;
	for(int i = 0; i < m; i++) {
		int l , r;
		cin >> l >> r;
		paa.push_back({l,r});
		l--;r--;
		cur[l]++;
		cur[r + 1]--;
	}
	vector<int> pre(n + 1);
	pre[0] = cur[0];
	for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + cur[i];
	vector<int> cnt(n + 1, 0);
	int add = 0;
	for(int i = 1; i <= n; i++) {
		cnt[i] = cnt[i - 1];
		if(pre[i - 1] == 1) cnt[i]++;
		if(pre[i - 1] == 0) add++;
	}
	for(auto &pa: paa) {
		int ans = cnt[pa.second] - cnt[pa.first - 1];
		cout << ans + add << endl;
	}
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