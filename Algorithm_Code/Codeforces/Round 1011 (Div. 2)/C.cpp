#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 x, y;
    cin >> x >> y;
    if(x == y) {
        cout << -1 << "\n";
        return;
    }
    int cntx = log2(x) + 1;
    int cnty = log2(y) + 1;
    int mx = max(cntx, cnty);
    i64 ans = (1 << mx) - max(x, y);
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