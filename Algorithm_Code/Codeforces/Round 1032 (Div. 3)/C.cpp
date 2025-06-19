#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n,m;
    cin >> n >> m;
    int mx = -1;
    int cnt = 0;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx,a[i][j]);
        }
    }
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mx == a[i][j]) {
                row[i]++;
                col[j]++;
                cnt++;
            }
        }
    }
    int cntmx = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == mx) cntmx = max(cntmx,row[i] + col[j] - 1);
            else cntmx = max(cntmx,row[i] + col[j]);
        }
    }
    if(cntmx >= cnt) cout << mx - 1 << "\n";
    else cout << mx << "\n";
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