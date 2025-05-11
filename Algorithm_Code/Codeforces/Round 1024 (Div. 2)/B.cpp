#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
	cin >> n;
	int tem = 0;
	cin >> tem;
	int l = 0, r = 0;
	for(int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if(abs(a) < abs(tem)) l++;
		else r++;
	}
	if(r >= l) cout << "YES" << endl;
	else {
		if(r + 1 == l) cout << "YES" << endl;
		else cout << "NO" << endl; 
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