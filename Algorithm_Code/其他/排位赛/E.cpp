#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;



void solve()
{
	int n = 0;
	cin >> n;
	vector<int> v(n);
	set<int> se;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		se.insert(v[i]);	
	} 
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int a = v[i] | v[j];
			if(!se.count(a)) {
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";
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