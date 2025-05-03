#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int INF = 2e5 + 5;
vector<int> pa, sz;

int find(int x) {
    if (pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        pa[y] = x;
        sz[x] += sz[y];
    }
}

void solve() {
    int n;
    cin >> n;

    pa.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) pa[i] = i;

    vector<int> cnt(n + 1, 0);
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 1 && cnt[i] != 4) continue;
        for (int j : graph[i]) {
            if (cnt[j] != 1 && cnt[j] != 4) continue;
            merge(i, j);
        }
    }

    int max_size = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            max_size = max(max_size, sz[i]);
        }
    }

    cout << max_size << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int T = 1;
    // cin >> T;
    while (T--) solve();
}
