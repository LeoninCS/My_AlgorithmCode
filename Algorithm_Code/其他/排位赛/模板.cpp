#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n = 0;
	cin >> n;
	vector<i64> cha(n + 5, 0);
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		i64 add = l + r;
		cha[l] += add;
		cha[r + 1] -= add; 
	}
	vector<i64> pre(n + 1, 0);
	i64 mx = 0;
	int idx = -1;
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + cha[i];
		if(pre[i] > mx) {
			mx = pre[i];
			idx = i;
		}
	}
	cout << idx << endl;
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