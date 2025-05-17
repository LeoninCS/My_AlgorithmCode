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
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) {
		if(v[i] == 0) {
			if((i - 1 >= 0 && v[i - 1] == 0 ) || (i + 1 < n && v[i + 1] == 0)) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	int cnt = count_if(v.begin(),v.end(),[&](const int a) ->bool{ return a != 1;});
	if(cnt) cout << "No" << endl;
	else cout << "Yes" << endl;
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