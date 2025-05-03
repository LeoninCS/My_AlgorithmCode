#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
vector<int> v;
set<int> se;
int n;
int vis[105];

void dfs(int idx, int sum)
{
	se.insert(abs(sum));
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		dfs(i + 1, sum + v[i]);
		dfs(i + 1, sum - v[i]);
		dfs(i + 1, v[i] - sum);
		vis[i] = 0;
	}	
}

void solve()
{
	cin >> n;
	for(int i = 0 ;i < n; i++) {
		int add = 0;
		cin >> add;
		v.push_back(add);
	}
	for(int i = 0; i < n; i++) {
		vis[i] = 1;
		dfs(i,v[i]);
		vis[i] = 0;	
	} 
	int ans = se.size();
	//for(auto s:se) cout << s << " ";
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