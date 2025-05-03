#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	set<i64> se;
	se.insert(1);
	for(int i = 1; i < 63 ; i++) {
		i64 val = pow(2,i);
		se.insert(i);
	}
	int n = 1;
	cin >> n;
	int cnt = 0;
	while(n--) {
		i64 val;
		cin >> val;
		if(se.count(val)) cnt++;
	}
	cout << cnt;
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