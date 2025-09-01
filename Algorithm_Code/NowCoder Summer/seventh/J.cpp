#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using int128 = __int128_t;

const int inf = 1e9;
const i64 INF = 1e18;
i64 mod = 998244353;
ll fast_pow(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (ll)((int128)res * base % mod);
        base = (ll)((int128)base * base % mod);
        exp /= 2;
    }
    return res;
}

void solve()
{
	i64 a, b, c, d;
    cin >> a >> b >> c >> d;
    i64 ans = 1;
    while(__gcd(a, c) != 1) {
        i64 g = __gcd(a, c);
        a /= g;
        c /= g;
        int mi = min(b, d);
        ans = (ans * fast_pow(g, mi, mod)) % mod;
        d -= b;
        if(d <= 0) break; 
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