#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 a, b, x, y;
    cin >> a >> b >> x >> y;
    if(a % 2 == 1 && a == b + 1) {
        cout << y << "\n";
        return;
    }
    if(a > b) cout << -1 << "\n";
    else if(a == b) {
        cout << 0 << "\n";
    }
    else {
        i64 ans = 0;
        if(a&1) {
            a++;
            ans += x;
        }
        b -= a;
        i64 add = x + min(x, y);
        ans += ((b / 2) * add + (b % 2) * min(x, y));
        cout << ans << "\n";
    }
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