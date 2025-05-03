#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
	int n, k;
	cin >> n >> k;
	int tem = k;
	int mx = 1;
	int cnt = 1;
	int flag = true;
	while(tem) {
		if(tem & 1 && flag)  {
		 mx *= 2;
		} else {
			flag = false;	
		}
		cnt *= 2;
		tem >>= 1;
	}
	cnt /= 2;
	//cout << cnt << "---------" << mx << endl; 
	if(n > cnt) {
		for(int i = 0; i < min(n, mx); i++) cout << i << " ";
		for(int i = min(n, mx); i < n; i++) cout << k << " ";
	} else {
		for(int i = 0; i < min(n - 1, mx); i++) cout << i << " ";
		for(int i = min(n - 1, mx); i < n; i++) cout << k << " ";
	}
	cout << endl;
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