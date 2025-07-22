head
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        i64 a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b > d) {
            ans += (a + b - d);
        } else {
            ans += max(0LL, a - c);
        }
    }
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