#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> gra(n);
    x--, y--;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> pre(n, 1e9),vis(n, 0);
    pre[x] = 0;
    pq.push({x, 0});
    while(!pq.empty()) {
        auto [u,_] = pq.top();
        //cout << u << " ";
        pq.pop();
        vis[u] = 1;
        if(u == y) break;
        for(int v:gra[u]) {
            if(vis[v]) continue;
            pre[v] = u;
            pq.push({v,u});
        }
    }
    vector<int> ans;
    while(true) {
        ans.push_back(y);
        if(y == x) break;
        y = pre[y];
    }
    reverse(ans.begin(),ans.end());
    for(int xx : ans) cout << xx + 1 << " ";
    cout << "\n";
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