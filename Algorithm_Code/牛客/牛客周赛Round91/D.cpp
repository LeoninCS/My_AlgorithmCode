#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

vector<int> pa;

int find(int x) 
{
	if (pa[x] != x) pa[x] = find(pa[x]);
	return pa[x];
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	pa[y] = x;
}

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> a(n);
	vector<int> b(200005, -1);
	pa.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]] = i;
		pa[i] = i;
	} 
	for(int i = 0; i < n; i++) {
		if (b[a[i] - 1] != -1) merge(b[a[i] - 1], i);
		if (b[a[i] + 1] != -1) merge(b[a[i] + 1], i);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (find(i) == i) ans++;
	}
	cout << ans - 1 << '\n';
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
