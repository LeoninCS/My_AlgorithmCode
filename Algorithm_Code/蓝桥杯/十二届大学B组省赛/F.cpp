#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n = 0;
	cin >> n;
	n %= (3600000 * 24);
	int HH = n / 3600000;
	n %= 3600000;
	int MM = n / 60000;
	n %= 60000;
	int SS = n / 1000;
	if(HH < 10) cout << 0 << HH;
	else cout << HH;
	cout << ":";
	if(MM < 10) cout << 0 << MM;
	else cout << MM;
	cout << ":";
	if(SS < 10) cout << 0 << SS;
	else cout << SS; 
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