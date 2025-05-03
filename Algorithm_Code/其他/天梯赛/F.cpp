#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n;
	cin >> n;
	vector<double> a(n);
	vector<double> b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	double ans = 0;
	for(int i = 0; i < n; i++) ans += (a[i] - b[i]) * (a[i] - b[i]);
	ans /= n;
	printf("%.5f", ans);
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
