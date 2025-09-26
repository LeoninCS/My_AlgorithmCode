#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<vector<int>> lar(n);
    vector<int> cnt(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--, v--;
        if(x < y) {
            lar[u].push_back(v); // pu > pv
            cnt[v]++;
        } else {
            lar[v].push_back(u); // pv > pu
            cnt[u]++;
        }
    }
    vector<int> ans(n);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(cnt[i] == 0) q.push(i);
    }
    int nn = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans[u] = ++nn;
        for(auto v : lar[u]) {
            cnt[v]--;
            if(cnt[v] == 0) q.push(v);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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