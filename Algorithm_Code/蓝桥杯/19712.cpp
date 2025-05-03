#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

pair<int,int> mv[8] = {{0,1},{1,1},[1,0],{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

void solve()
{
   int n, k;
   cin >> n >> k;
   veceor<vector<int>> gra(n,vector<int>(n));
   veceor<vector<int>> vis(n,vector<int>(n,0));
   for(int i = 0; i < n; i++) {
   	for(int j = 0; j < n; j++) {
   		cin >> gra[i][j];
	   }
   }
   vector<int> ans(n * n);
   int cnt = 1;
   function<bool(int,int,int)> dfs = [&](int x, int y,int sum) -> bool {
		if(x == n - 1 && y == n - 1 && cnt == n * n) {
			return true;
		}
		for(int i = 0; i < 8; i++) {
			mv_x = x + mv[i].first;
			mv_y = y + mv[i].second;
			if(i % 2 == 0) {
				if(mv_x <n && mv_x >= 0 && mv_y < n && mv_y >= 0 && 
				 !vis[mv_x][mv_y]) {
				 	cnt++;
				 	dfs(mv_x,mv_y,sum + gra[mv_x][mv_y]);
				 	cnt--;
				 }
			}
		}
   };
   if(dfs({0,0})) {
   	for(int i = 0; i < n * n; i++) {
   		cout << ans[i];
	   }
   } else {
   	cout << -1;
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