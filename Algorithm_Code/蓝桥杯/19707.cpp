#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    vector<vector<int>> gra(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        vector<int> vis(n, 0);
        vector<int> path(n, -1);
        vector<int> dis(n, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, u});
        dis[u] = 0;
        path[u] = u;
        
        while (!pq.empty()) {
            auto pa = pq.top();
            pq.pop();
            int d = pa.first;
            int st = pa.second;
            if (vis[st]) continue;
            vis[st] = 1;
            if (st == v) break;
            for (auto &nxt : gra[st]) {
                if (!vis[nxt] && d + 1 < dis[nxt]) {
                    dis[nxt] = d + 1;
                    path[nxt] = st;
                    pq.push({d + 1, nxt});
                }
            }
        }

        set<int> se;
        while (v != u) {
            se.insert(c[v]);
            v = path[v];
        }
        se.insert(c[u]);
        int ans = se.size();
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    while (T--) solve();
    
    return 0;
}
