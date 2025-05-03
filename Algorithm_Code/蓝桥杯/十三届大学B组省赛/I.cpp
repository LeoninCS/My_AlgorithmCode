#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

i64 mod =  1000000007;

i64 f[105][105][105];

i64 dfs(int x, int y,int z) {
	if(x > z) return 0;
	if(x <= 0 || y < 0 || z < 0) return 0;
	if(x == 1 && y == 0 && z == 1) return 1;
	if(f[x][y][z] != -1) return f[x][y][z];
	f[x][y][z] = dfs(x * 2,y - 1, z) + dfs(x - 1, y, z - 1);
	return f[x][y][z] % mod;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	memset(f, - 1, sizeof(f));
	cout << dfs(2, n, m);
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