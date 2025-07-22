#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	i64 a, b, k;
    cin >> a >> b >> k;
    i64 g = __gcd(a, b);
    a /= g;
    b /= g;
    if(a <= k && b <= k) cout << 1 << "\n";
    else cout << 2 << "\n";
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