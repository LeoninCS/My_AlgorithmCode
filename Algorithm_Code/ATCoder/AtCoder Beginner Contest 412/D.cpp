#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    map<pair<int,int>,int> mp;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mp[{a, b}]++;
        mp[{b, a}]++;
    }
    vector<int> vis(n, 0);
    int cnt = 0;
    int ans = 10000;
    vector<int> path;
    auto dfs = [&](auto & dfs,int cur, int num)->void {
        if(num == n) {
            if(cnt == 0) {
                ans = min(ans, abs(m - n));
            } else if(mp.count({cur, 0}) || mp.count({0, cur})) {
                ans = min(ans,(m - n) + 2 * cnt); 
            } else {
                ans = min(ans,(m - n) + 2 * cnt + 2);
            }
            
            
            for(int i = 0; i < n; i++) {
                cout << path[i] + 1 << " ";
            } 
            cout << "cnt " << cnt << " m " << m << " n " << n << "\n";
            
            
            return;
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            path.push_back(i);
            vis[i] = 1;
            if(mp.count({cur, i}) || mp.count({i, cur})) {
                dfs(dfs, i, num + 1);    
            } else {
                cnt++;
                dfs(dfs, i, num + 1);
                cnt--;
            }
            vis[i] = 0;
            path.pop_back();
        }
    };
    path.push_back(0);
    vis[0] = 1;
    dfs(dfs, 0, 1);
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	//cin >> T;
	while(T--) solve();
	
	return 0;
}