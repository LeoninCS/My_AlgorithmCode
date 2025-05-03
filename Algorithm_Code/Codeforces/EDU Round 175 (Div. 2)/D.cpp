#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
const i64 INF = 1e18;
const i64 mod = 998244353;

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> gra(n + 1);
    vector<int> par(n + 1);
    vector<int> lev(n + 1, 0);
    lev[1] = 1;

    for (int i = 2; i <= n; i++) { 
        int p;
        cin >> p;
        gra[p].push_back(i);
        par[i] = p;
        lev[i] = lev[p] + 1;
    }

    vector<int> se(n);
    for (int i = 1; i <= n; i++) se[i - 1] = i;

    sort(se.begin(), se.end(), [&](const int &a, const int &b) {
        return lev[a] < lev[b];
    });

    vector<int> levsum(n + 1, 0);
    vector<int> f(n + 1, 0);
    levsum[0] = 1;

    for (auto &i : se) {
        if (lev[i] == 1 || lev[i] == 2) {
            f[i] = (f[i] + levsum[lev[i] - 1]) % mod;
        } else {
            f[i] = ((f[i] + levsum[lev[i] - 1] - f[par[i]]) % mod + mod) % mod;
        }
        levsum[lev[i]] = (f[i] + levsum[lev[i]]) % mod;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + f[i]) % mod;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
