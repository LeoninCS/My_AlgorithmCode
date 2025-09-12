#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9;

void solve()
{
    i64 n, m, q;
    cin >> n >> m >> q;
    vector<i64> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<pair<int,char>> c;
    for(i64 x : a) c.push_back({x,'a'});
    for(i64 x : b) c.push_back({x,'b'});
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<vector<int>> prec(n + m + 1, vector<int>(2, 0));
    for(int i = 1; i <= m + n; i++) {
        prec[i][0] = prec[i - 1][0];
        prec[i][1] = prec[i - 1][1];
        if(c[i - 1].second == 'a') prec[i][0]++;
        else prec[i][1]++;
    }
    vector<i64> prea(n + 1);
    vector<i64> preb(m + 1);
    for(int i = 1; i <= n; i++) prea[i] = prea[i - 1] + a[i - 1];
    for(int i = 1; i <= m; i++) preb[i] = preb[i - 1] + b[i - 1];
    while(q--) {
        i64 x, y, z;
        cin >> x >> y >> z;
        int cnta = prec[n + m][0] - prec[n + m - z][0];
        int cntb = prec[n + m][1] - prec[n + m - z][1];
        i64 ans = 0;
        //cout << cnta << " " << cntb << "\n";
        if(cnta > x) ans = prea[n] - prea[n - x] + preb[m] - preb[m - (z - x)];
        else if(cntb > y) ans = prea[n] - prea[n - (z - y)] + preb[m] - preb[m - y];
        else ans = prea[n] - prea[n - cnta] + preb[m] - preb[m - cntb];
        cout << ans << "\n";   
    }
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