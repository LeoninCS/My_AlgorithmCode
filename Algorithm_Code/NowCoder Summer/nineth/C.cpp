#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> nxt(n);
    vector<int> cnt(n);
    vector<int> vis(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        nxt[u].push_back(v);
        cnt[v]++;
    }
    int mxx = 0,mx = 0, idx = 0;
    for(int i = 0; i < n; i++) {
        if(cnt[i] == 0 && nxt[i].size() == 0) {
            mxx = max(mxx, a[i]);     
            vis[i] = 1;
        } else {
            if(a[i] > mx) {
                mx = a[i];
                idx = i;
            }
        }
    }
    a[idx] = max(a[idx], mxx);
    vector<int> na(a);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[j]) continue;
            if(cnt[j] == 0) {
                vis[j] = 1;
                for(int v:nxt[j]) {
                    cnt[v]--;
                    na[i] = max(na[i],a[i] + na[j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans,na[i]);
    cout << ans << "\n";
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