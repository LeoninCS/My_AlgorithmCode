#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

const i64 mod = 998244353;

i64 inv(i64 aa, i64 a)
{
    i64 b = mod - 2;
    i64 res = 1;
    while(b) {
        if(b % 2 == 1) res = (a * res) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    res = (aa % mod * res) % mod;
    return res;
}


struct line
{
    i64 l, r, p, q;
};


void solve()
{
	int n, m;
    cin >> n >> m;
    i64 all = 1;
    vector<line> v(n); 
    vector<int> ans(m + 1);
    i64 x = 1;
    for(int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r >> v[i].p >> v[i].q;
        x = (x * inv(v[i].q - v[i].p, v[i].q)) % mod;
    }
    
    sort(v.begin(),v.end(), [&](line a, line b) -> bool {
        return a.r < b.r;
    });
    ans[0] = x;
    for(int i = 0; i < n; i++) {
        int l = v[i].l;
        int r = v[i].r;
        i64 p = inv(v[i].p, v[i].q) % mod;
        i64 np = inv(v[i].q - v[i].p, v[i].q) % mod;
        ans[r] = (ans[r] + ans[l - 1] * inv(1, np) % mod * p % mod) % mod;
    }
    cout << ans[m] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}