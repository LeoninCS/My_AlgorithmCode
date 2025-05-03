#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
i64 mod = 1000000007;

void solve()
{
	i64 n,m_a,m_b;
	cin >> n;
	cin >> m_a;
	vector<i64> x_a(m_a);
	for(i64 i = 0; i < m_a; i++) {
		cin >> x_a[i];
	} 
	cin >> m_b;
	vector<i64> x_b(m_a, 0);
	for(i64 i = 0; i < m_a; i++) {
		if(i >= m_a - m_b) cin >> x_b[i];
	}
	vector<i64> x(m_a);
	for(i64 i = 0; i < m_a; i++) {
		x[i] = max({(i64)2, x_a[i] + 1, x_b[i] + 1});
		//cout << x[i] << " ";
	}
	i64 add = 1;
	i64 ans = 0;
	for(i64 i = m_a - 1; i >= 0; i--) {
		ans += (x_a[i] - x_b[i]) * add;
		ans %= mod;
		add *= x[i];
		add %= mod;
	}	
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