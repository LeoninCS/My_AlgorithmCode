#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int x = 0;
    cin >> x;
    int a = 0, b = 0, c = 0;
    int ans = 2;
    while(a < x) {
        int tem = c;
        c = b;
        b = a;
        a = c * 2 + 1;
        ans++;
        //cout << a << " " << b << " " << c << "\n";
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