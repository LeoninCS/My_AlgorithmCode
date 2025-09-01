#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    if(b - (a + 1) * 2 > 0 || d - (c + 1) * 2 > 0 || (c < 0 && d < 0)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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