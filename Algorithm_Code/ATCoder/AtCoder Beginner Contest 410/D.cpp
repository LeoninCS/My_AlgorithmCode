#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> gra(n + 1);
    for(int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        gra[a].push_back({b,w});
    }
    vector<vector<int>> vis(n + 1,vector<int>(1025, 0));
    queue<pair<int,int>> q;
    q.push({1,0});
    vis[1][0] = 1;
    while(q.size()) {
        auto [v,val] = q.front();
        q.pop();
        for(auto [to, x] : gra[v]) {
            if(vis[to][val ^ x]) continue;
            vis[to][val ^ x] = 1;
            q.push({to,val ^ x});
        } 
    }
    int ans = -1;
    for(int i = 0; i < 1025; i++) {
        if(vis[n][i]) {
            ans = i;
            break;
        }
    }
    cout << ans;
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