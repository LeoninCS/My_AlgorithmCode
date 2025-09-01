#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;


i64 factorial(int n) {
    i64 res = 1;
    for (int i = 2; i <= n; ++i) res = res * i % mod;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gra(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }

    
    vector<int> color(n, -1);
    queue<int> q;
    bool is_bipartite = true;
    q.push(0);
    color[0] = 0;
    while (!q.empty() && is_bipartite) {
        int u = q.front();
        q.pop();
        for (int v : gra[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            } else if (color[v] == color[u]) {
                is_bipartite = false;
                break;
            }
        }
    }
    if (!is_bipartite) {
        cout << 0 << "\n";
        return;
    }

    vector<int> north, south;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) north.push_back(i);
        else south.push_back(i);
    }
    if (north.empty() || south.empty()) {
        cout << 0 << "\n"; 
        return;
    }

    
    i64 ans = 2; 

    vector<int> degree(n);
    for (int i = 0; i < n; ++i) degree[i] = gra[i].size();
    int leaf_north = 0, leaf_south = 0;
    for (int u : north) if (degree[u] == 1) leaf_north++;
    for (int u : south) if (degree[u] == 1) leaf_south++;

    ans = ans * factorial(leaf_north) % mod;
    ans = ans * factorial(leaf_south) % mod;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
