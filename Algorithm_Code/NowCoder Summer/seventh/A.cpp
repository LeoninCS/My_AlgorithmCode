// #define LOCAL_DEBUG
// #pragma GCC optimize("O2")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2")
// =================================================================================================
#include <bits/stdc++.h>
using namespace std;
// =================================================================================================
// ||                                        DEBUG MACRO                                          ||
// =================================================================================================
#ifdef LOCAL_DEBUG
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(__int128_t x)
{
    string s;
    if (x == 0)
    {
        cerr << "0";
        return;
    }
    bool neg = x < 0;
    if (neg)
        x = -x;
    while (x > 0)
    {
        s += (x % 10) + '0';
        x /= 10;
    }
    if (neg)
        cerr << '-';
    reverse(s.begin(), s.end());
    cerr << s;
}
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _debug() { cerr << "]\n"; }
template <typename T, typename... V>
void _debug(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _debug(v...);
}
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _debug(x)
#else
#define debug(x...)
#endif
// =================================================================================================
// ||                                      TYPE ALIASES & MACROS                                  ||
// =================================================================================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using int128 = __int128_t;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define dep(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define F first
#define S second
// =================================================================================================
// ||                                     MATHEMATICS & NUMBER THEORY                             ||
// =================================================================================================
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
ll mod_inverse(ll n, ll mod) { return fast_pow(n, mod - 2, mod); }
ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
// =================================================================================================
// ||                                       MAIN LOGIC                                            ||
// =================================================================================================
const int SIEVE_MAX = 1e6 + 5;
vi min_prime(SIEVE_MAX);
vi primes;
void sieve()
{
    iota(all(min_prime), 0);
    for (int i = 2; i * i < SIEVE_MAX; ++i)
    {
        if (min_prime[i] == i)
        {
            for (int j = i * i; j < SIEVE_MAX; j += i)
            {
                if (min_prime[j] == j)
                    min_prime[j] = i;
            }
        }
    }
    rep(i, 2, SIEVE_MAX) if (min_prime[i] == i) primes.pb(i);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vis(n + 1, 0);
    for(int x: primes) {
        if(x > n) break; 
        vis[x] = 1; 
    }
    int num = 0;
    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        if(i % 10 == 2 || i % 10 == 3 || i % 10 == 7 || i % 10 == 8) vis[i] = 1;
    }
    for(int i = 2; i <= n; i++) if(vis[i]) ans.push_back(i);
    for(int x:ans) for(int y:ans) for(int z:ans) 
    {int cc = x * y * z; if((int)sqrt(cc) * (int)sqrt(cc) == cc) cout << x << " " << y << " " << z << "\n";}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}