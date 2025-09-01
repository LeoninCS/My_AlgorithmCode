#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

struct pab {
    int p, a, b;
};

void solve()
{
	int n;
    cin >> n;
    vector<pab> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].p >> v[i].a >> v[i].b;
    }
    
    vector<vector<int>> ans(n + 1, vector<int>(1001, 0));
    for(int i = 0; i <= 1000; i++) ans[n][i] = i;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= 1000; j++) {
            if(j <= v[i].p) {
                int nxt = j + v[i].a;
                ans[i][j] = ans[i + 1][nxt];
            } else {
                int nxt = max(0, j - v[i].b);
                ans[i][j] = ans[i + 1][nxt];
            }
        }
    }
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i - 1].b;
    }
    //cout << pre[n] << " ";
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        int idx = upper_bound(pre.begin(), pre.end(), x - 1000) - pre.begin();
        if(idx > n) cout << x - pre[n] << "\n";
        else {
            x -= pre[idx];
            cout << ans[idx][x] << "\n";
        }
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