#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 INF = 1e18;

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<int> x(m), y(m), z(m);
	int a = 0, b = 0;
	for(int i = 0 ; i < m; i++) {
		cin >> x[i] >> y[i] >> z[i];
		a ^= x[i];
		a ^= y[i];
		b ^= z[i]; 
	} 
	cout << a << " " << b;
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
