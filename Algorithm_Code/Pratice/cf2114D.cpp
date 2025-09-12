#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    vector<int> pa(n + 1);
    vector<i64> dp(n + 1, -1);
    vector<vector<int>> son(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    int cnt = 0;
    dp[0] = 0;
    pa[0] = 0;
    pa[1] = 0;
    while(q.size()) {
        int k = q.size();
        for(int i = 0; i < k; i++) {
            int u = q.front();
            q.pop();
            dp[u] = dp[pa[pa[u]]] - a[pa[u]] + a[u];
            dp[u] = max(dp[u],a[u]);
            for(int &v: son[u]) {
                if(dp[v] != -1) continue;
                pa[v] = u;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
     //cout << dp[i] << " " << dp[pa[i]] << " "<<  ans[i] << " " << "\n";
       cout << dp[i] << " ";
    }
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