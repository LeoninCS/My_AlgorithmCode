#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

i64 p = 1e9 + 7;

i64 inv[100005];


void solve()
{
	i64 a, b, k;
    cin >> a >> b >> k;
    int ans1 = (a * k - k + 1) % p;
    
    int ans2 = k;
    for(i64 i = 1; i <= a; i++) ans2 = ans2 * (ans1 - i + 1) % p *  inv[i] % p;
    ans2 = (b * ans2 - ans2 + 1 + p) % p;
    cout << ans1 << " " << ans2 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inv[1] = 1;
    for(int i = 2; i < 100005; i++) inv[i] = (p - p / i) * inv[p % i] % p;

	int T = 1;
	cin >> T;
	while(T--) solve();
	
	return 0;
}