#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n+1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        fa[x] = y;
        return true;
    }
};

int n, m;
vector<vector<pair<int,int>>> mst;
vector<bool> vis;

pair<int,int> dfs(int u, int target, int cur_min, int cur_max) {
    if (u == target) return {cur_min, cur_max};
    vis[u] = true;
    pair<int,int> best = {INF, -INF};

    for (auto &[v, w] : mst[u]) {
        if (!vis[v]) {
            auto [min_w, max_w] = dfs(v, target, min(cur_min, w), max(cur_max, w));
            if (min_w != INF) {
                if (min_w + max_w < best.first + best.second) {
                    best = {min_w, max_w};
                }
            }
        }
    }
    vis[u] = false;
    return best;
}

void solve() {
    cin >> n >> m;
    vector<Edge> edges(m);
    int min_edge_weight = INF;
    int min_u = -1, min_v = -1;
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        if (edges[i].w < min_edge_weight) {
            min_edge_weight = edges[i].w;
            min_u = edges[i].u;
            min_v = edges[i].v;
        }
    }
    
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    mst.assign(n+1, {});
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst[e.u].emplace_back(e.v, e.w);
            mst[e.v].emplace_back(e.u, e.w);
        }
    }

    vis.assign(n+1, false);
    auto [a, b] = dfs(1, n, INF, -INF);
    
    // 计算到最小边顶点的路径
    vis.assign(n+1, false);
    auto [c_u, d_u] = dfs(1, min_u, INF, -INF);
    
    vis.assign(n+1, false);
    auto [c_v, d_v] = dfs(1, min_v, INF, -INF);
    
    // 计算两种可能的 c + max(b, d)
    int option1 = INF, option2 = INF;
    if (c_u != INF) option1 = c_u + max(b, d_u);
    if (c_v != INF) option2 = c_v + max(b, d_v);
    
    // 计算最终结果
    int ans = min(a + b, min(option1, option2));
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}