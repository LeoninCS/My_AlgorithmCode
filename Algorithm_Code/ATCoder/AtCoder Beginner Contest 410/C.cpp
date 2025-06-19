#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		a[i] = i;
	}
	int cnt = 0;
	while(q--) {
		int choose;
		cin >> choose;
		if(choose == 1) {
			int p, x;
			cin >> p >> x;
			int idx = 0;
			if( (p + cnt) % n == 0) idx = n;
			else idx = (p + cnt) % n;
			a[idx] = x;  
			
		} else if(choose == 2) {
			int p;
			cin >> p;
			int idx = 0;
			if( (p + cnt) % n == 0) idx = n;
			else idx = (p + cnt) % n;
			cout << a[idx] << "\n";
		} else {
			int k;
			cin >> k;
			k %= n;
			cnt += k;
			cnt %= n;			
		}
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