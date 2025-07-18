#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;
 
vector<i64> pre(1e6+10,0);

void solve()
{
	i64 n, m;
    cin >> n >> m;
    if(pre[n] < m || n > m) {
        cout << -1 << "\n";
        return;
    }
    if(pre[n] == m) {
        cout << n << "\n";
        for(int i = 1; i < n; i++) cout << n << " " << i << "\n";
        return;
    }
    if(n == m) {
        cout << 1 << "\n";
        for(int i = 2; i <= n; i++) cout << 1 << " " << i << "\n";
        return;
    }
    int mx = 0;
    for(int i = 0; i <= n; i++) {
        if(pre[i]  + (n - i - 1) >= m) break;
        mx = i;
    }
    m -= pre[mx];
    m -= (n - mx);
    cout << mx << "\n";
    for(int i = 1; i < mx; i++) cout << mx << " " << i << "\n";
     cout << m + 1 << " " << n << "\n";
    for(int i = mx + 1; i <= n - 1; i++) cout << 1 << " " << i << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
    for(i64 i = 1; i <= 1e6 + 5; i++) {
        pre[i] = pre[i - 1] + i;
    }

	int T = 1;
	cin >> T;
    while(T--) solve();
	
	return 0;
}