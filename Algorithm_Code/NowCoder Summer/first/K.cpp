#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

const int N = 2e5 + 5;
int e[N][3];
int cnt[N];
bool vis[N][3];
int ans[N][3];


pair<int,int> ne(pair<int,int> u)
{
	auto[f,s] = u;
	int v = e[f][s];
	int st = 0;
	while(e[v][st] != f) st++;
	return {v, st};  
}

pair<int,int> val(pair<int,int> u)
{
	pair<int,int> v = ne(u);
	return min(u, v);  
}

void solve()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int d;
		cin >> d;
        cnt[i] = d;
		for(int j = 0; j < d; j++) {
			cin >> e[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < cnt[i]; j++) {
			if(vis[i][j]) continue;
			pair<int,int> u = {i, j};
			pair<int,int> cur = u;
			set<pair<int,int>> se;
			do {
				auto[f,s] = cur;
				vis[f][s] = 1;
				se.insert(val(cur));
				cur = ne(cur);
				cur.second = (cur.second + 1) % cnt[cur.first];	
			} while(cur != u);
			cur = u;
			do {
				auto [f,s] = cur;
				ans[f][s] = se.size();
				cur = ne(cur);
				cur.second = (cur.second + 1) % cnt[cur.first];
			} while(cur != u);
		}
        cout << ans[i][0] << "\n";
	} 
	
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