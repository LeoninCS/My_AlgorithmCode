#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int cal(int year) {
	int ans = 0;
	ans = year / 4 - year / 100 + year / 400;
	return ans;
} 

void solve()
{
	int x, y;
	cin >> x >> y;
	/*for(int i = 0; i < 200; i++) {
		cout << i <<  " " << cal(i) << endl;
	}*/
	int ans = cal(y) - cal(x);
	if((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0)) ans++;
	cout << ans << endl;
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