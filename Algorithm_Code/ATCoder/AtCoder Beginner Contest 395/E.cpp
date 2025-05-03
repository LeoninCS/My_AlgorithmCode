#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    i64 n, m, x;
    cin >> n >> m >> x;
    
    vector<vector<i64>> graph(2 * n + 1);
    for(i64 i = 1; i <= n; i++) {
    	graph[i].push_back(i + n);
    	graph[i + n].push_back(i);
	}
	for (i64 i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v + n].push_back(u + n);
    } 
    
    vector<i64> dis(2 * n + 1, 1e18);
    vector<i64> vis(2 * n + 1, 0);
    
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = 1;

        for(auto &v: graph[u]) {
        	if(vis[v]) continue;
        	if(abs(v - u) == n) {
        		if(d + x < dis[v]) {
        			dis[v] = d + x;
        			pq.push({dis[v], v});
				}
			} else {
				if(d + 1 < dis[v]) {
					dis[v] = d + 1;
					pq.push({dis[v], v});
				}
			}
		}
    }
    
    //for (int i = 1; i <= n; i++) 
    cout << min(dis[n],dis[n + n]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    //cin >> T;
    while (T--) solve();
}
