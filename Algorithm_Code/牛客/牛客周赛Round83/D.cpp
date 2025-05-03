#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	i64 t = 0;
	cin >> t;
	if(t == 1) {
		cout << 0 << " " << 0 << endl;
		return;
	} else if(t == 2) {
		cout << 1 << " " << 0 << endl;
		return;
	} else if(t == 3) {
		cout << 1 << " " << -1 << endl;
		return;
	} else if( t == 4) {
		cout << 0 << " " << -1 << endl;
		return;
	}
	t -= 4;
	i64 cnt = 1;
	while(t >= (4 * cnt + 4)) {
		t -= (4 * cnt + 4);
		cnt += 2; 
	}
	int x = -(cnt / 2), y = -(cnt / 2) - 1;
	if(t == 0) cout << x << " " << y << endl; 
	else if(t >= 1 && t <= cnt + 1) cout << x - 1 << " " << y + t - 1 << endl;
	else if(t >= cnt + 2 && t <= 2 * cnt + 3) cout << x + t - cnt - 3 << " " << y + cnt + 1 << endl; 
	else if(t >= 2 * cnt + 4 && t <= 3 * cnt + 5) cout << x + cnt + 1 << " " << - y - t + 2 * cnt + 4 << endl;
	else cout << -x - t + 3 * cnt + 8   << " " << y - 1 << endl;
	cout << x << "------" << y << "-----" << cnt << endl;
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