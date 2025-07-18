#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    int mi = 1e9, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    int ans = (mx - mi);
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