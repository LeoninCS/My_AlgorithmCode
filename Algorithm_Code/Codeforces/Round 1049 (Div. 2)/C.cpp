#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


i64 cal(i64 x) {
    i64 res = 0;
    while(x) {
        res++;
        x /= 10;
    }
    return res;
}

void solve()
{
	int n;
    cin >> n;
    vector<i64> a(n);
    i64 mi = 1e15, mx = -1;
    i64 mii = 1e15, mxx = -1;
    i64 ans = 0;
    for(i64 i = 0; i < n; i++) {
        cin >> a[i];
        if(i % 2 == 0) {
            mi = min(mi, 2 * a[i] + i);
            mii = min(mii, 2 * a[i] - i);
            ans += a[i];
        } else {
            mx = max(mx, 2 * a[i] + i);
            mxx = max(mxx, 2 * a[i] - i);
            ans -= a[i];
        }
    }
    ans += max({mx - mi, mxx - mii, (i64)(n - ((n + 1) % 2) - 1)});
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