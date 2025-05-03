#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n = 0;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	map<int,int> mp;
	for(int i = 0; i < n; i++) {
		if(mp.count(arr[i])) {
			arr[mp[arr[i]]] = 0;
			arr[i] = 0;
		} else {
			mp[arr[i]] = i;
		}
	}
	int mx = 0,cnt = 0;
	int l = -1, r = -1;
	for(int i = 0; i < n; i++) {
		if(arr[i] != 0) cnt++;
		else cnt = 0;
		if(cnt > mx) {
			l = i - cnt + 1;
			r = i;
			mx = cnt;
		}
	}
	if(l == -1 && r == -1) cout << 0 << endl;
	else cout << l + 1 << " " << r + 1 << endl;
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