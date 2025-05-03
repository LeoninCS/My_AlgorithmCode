#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;



void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for(int i = 0; i < n; i++) {
	cin >> v[i];
	}
	auto run = [&](int a, int b) {
		int x = 0, y = 0;
		char ch = v[a][b];
		v[a][b] = 'U';
		vector<vector<int>> vis1(n,vector<int>(m,0));
		while(1) {
			if(x == n - 1 && y == m - 1) return true;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'U') x--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'D') x++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'L') y--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'R') y++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(vis1[x][y]) break;
			vis1[x][y] = 1;
		}
		v[a][b] = 'D';
		vector<vector<int>> vis2(n,vector<int>(m,0));
		while(1) {
			if(x == n - 1 &&y == m - 1) return true;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'U') x--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'D') x++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'L') y--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'R') y++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(vis2[x][y]) break;
			vis2[x][y] = 1;
		}
		v[a][b] = 'L';
		vector<vector<int>> vis3(n,vector<int>(m,0));
		while(1) {
			if(x == n - 1 && y == m - 1) return true;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'U') x--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'D') x++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'L') y--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'R') y++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(vis3[x][y]) break;
			vis3[x][y] = 1;
		}
		v[a][b] = 'R';
		vector<vector<int>> vis4(n,vector<int>(m,0));
		while(1) {
			if(x == n - 1 && y == m - 1) return true;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'U') x--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'D') x++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'L') y--;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(v[x][y] == 'R') y++;
			if(x < 0 || x >= n || y < 0 || y >= m) break;
			if(vis4[x][y]) break;
			vis4[x][y] = 1;
		}
		v[a][b] = ch;
		return false;
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(run(i,j)) {
				cout << "YES";
				return;	
			}
		}
	}
	cout << "NO";
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