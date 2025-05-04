#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

int pa[200010];
int find (int x) 
{
	if(pa[x] != x) pa[x] = find(pa[x]);
	return pa[x];
}

void merge(int x,int y)
{
	x = find(x),y=find(y);
	pa[y] = x;
}

void solve()
{
    for(int i = 0; i < 200010; i++) pa[i] = i;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> gra(n + 1);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        gra[u].push_back(v);
        gra[v].push_back(u);
        merge(u,v);
    }
    if(n != m) {
        cout << "No\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(gra[i].size() != 2) {
            cout << "No\n";
            return;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(pa[i] == i) cnt++;
    }
    if(cnt != 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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