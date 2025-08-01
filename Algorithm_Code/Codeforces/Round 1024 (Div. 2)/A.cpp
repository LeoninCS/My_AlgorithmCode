#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m ,p, q;
	cin >> n >> m >> p >> q;
	int k = n / p;
	int mod = n % p;
	if(mod) {
		cout << "YES" << endl;
	} else {
	   	if(q * k == m) {
	   		cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
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