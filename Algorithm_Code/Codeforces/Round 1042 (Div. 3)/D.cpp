#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> gra(n);
    vector<int> cnt(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--,v--;
        gra[u].push_back(v);
        gra[v].push_back(u);
    }
    if(n == 2) {
        cout << 0 << "\n";
        return;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(gra[i].size() == 1) {
            cnt[gra[i][0]]++;
            ans++;
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(cnt[i], mx);
    }
    cout << ans - mx << "\n";
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