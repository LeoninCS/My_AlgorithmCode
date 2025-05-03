#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n = 0; cin >> n;
	vector<vector<int>> son(n);//存储子节点
	vector<int> vis(n,0);//用来确定根节点
	//输入
  for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vis[b] = 1;
		son[a].push_back(b);
	} 
	int ans = 0;
  //dfs找最大
	function<int(int)> dfs = [&](int cur) ->int {
		int h1 = 0;
		for(auto s:son[cur]) {
			int	h2 = dfs(s); //子链长度
			ans = max(ans,h1 + h2 + 1); //反复找最大
			h1 = max(h1, h2); //找出最长子链
		}
		return h1 + 1;
	};
  //从根节点开始dfs
	for(int i = 0; i < n; i++) {
		if(!vis[i]) dfs(i);
	}
  //找出最大则次大一定是最大减1
	cout << ans -1;
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