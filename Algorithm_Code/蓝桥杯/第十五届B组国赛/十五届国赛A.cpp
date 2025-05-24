#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int gcd(int a, int b) {
	if(a == 0 && b == 0) return 1;
	if(b == 0) return a;	
	return a % b == 0 ? b : gcd(b, a % b); 
}

void solve()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> vv(n,vector<int>(4));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) cin >> vv[i][j];
	}
	map<pair<int,int>,int> mp;
	for(auto & v: vv) {
		int chu = gcd(abs(v[2] - v[0]), abs(v[3] - v[1]));
		int vx = (v[2] - v[0]) / chu;
		int vy = (v[3] - v[1]) / chu;
		if(vx == 0) {
			if(vy == 0) mp[{v[0],v[1]}]++;
			else if(vy < 0) {
				for(int i = 0; v[1] + vy * i >= v[3]; i++) mp[{v[0] + vx * i, v[1] + vy * i}]++;	
			}
			else {
				for(int i = 0; v[1] + vy * i <= v[3]; i++) mp[{v[0] + vx * i, v[1] + vy * i}]++;	
			}
		} else if(vx < 0) {
			for(int i = 0; v[0] + vx * i >= v[2]; i++) mp[{v[0] + vx * i, v[1] + vy * i}]++; 
		} else if(vx > 0) {
			for(int i = 0; v[0] + vx * i <= v[2]; i++) mp[{v[0] + vx * i, v[1] + vy * i}]++;
		}
	}
	int ans = 0;
	for(auto& m: mp) {
		if(m.second > 1) ans++;
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
	
}