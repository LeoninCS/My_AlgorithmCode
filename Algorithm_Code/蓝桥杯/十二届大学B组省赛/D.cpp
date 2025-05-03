#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n = 2021041820210418;
	//i64 n = 4;
	vector<i64> v;
	for(i64 i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			i64 pb = n / i;
			v.push_back(i);
			if(pb != i) v.push_back(pb);
		}
	}
	i64 ans = 0;
	sort(v.begin(),v.end());
	//for(i64 i = 0; i < v.size(); i++) cout << v[i] << " ";
	for(i64 i = 0; i < v.size(); i++) {
		for(i64 j = 0; j < v.size(); j++) {
			for(i64 z = 0; z < v.size(); z++) {
				if(v[i] * v[j] * v[z] > n) break;
				if(v[i] * v[j] * v[z] == n) {
					cout << v[i] << " " << v[j] << " " << v[z] << endl;
					ans++;
				}
			}
		}
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
	
	return 0;
}