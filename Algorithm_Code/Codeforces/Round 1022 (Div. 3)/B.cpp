#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, x;
    cin >> n >> x;
    if(n == 1 && x == 0) {
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    if(x == 0) {
        if(n % 2 == 0) ans = n;
        else ans = n + 3;
    } else if(x == 1) {
        if(n % 2 == 0) ans = n + 3;
        else ans = n;
    } else {
        int cnt = 0;
        int tem = x;
        while(tem) {
            if(tem & 1) cnt++;
            tem >>= 1;
        }
        n -= cnt;
        if(n < 0) {
            ans = x;
        } else if(n % 2 == 0) {
            ans = x + n;
        } else {
            ans = x + n + 1;
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