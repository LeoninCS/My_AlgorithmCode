#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(105,0);
    int mx = 0,mi = 1000;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx,v[i]);
        mi = min(mi, v[i]);
    } 
    int ans = min(abs(s - mi), abs(mx - s)) + mx - mi;
    cout << ans << "\n";
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