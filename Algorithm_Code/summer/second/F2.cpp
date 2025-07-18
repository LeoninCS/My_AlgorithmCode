#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') v.push_back(i);
	}
	vector<int> vv;
	i64 k = v.size();
	if(k == 0) {
        cout << n << "\n";
        return;
    }
    vv.push_back(v[0] + n - 1 - v[k - 1]);
	for(int i = 1; i < k; i++) {
		vv.push_back(v[i] - v[i - 1] - 1);
	}
	sort(vv.begin(),vv.end());
    i64 ans = max(v[k - 1] - t - 1, 0LL);
    for(int i = 0; i < k - 1; i++) {
        ans += max(v[i] - 2 * t, 0LL);
    }
    cout << ans;
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