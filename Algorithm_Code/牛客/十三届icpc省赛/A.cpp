#include<bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<i64>> a(n,vector<i64>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int h,w;
    cin >> h >> w;
    for(int i = 0; i <= n - h; i++) {
        for(int j = 0; j <= m - w; j++) {
            if(a[i][j] == a[i + h - 1][j] && a[i][j] == a[i][j + w - 1] && a[i][j] == a[i + h - 1][j + w - 1]) {
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
    //cin >> T;
    while(T--) solve();
    return 0;
}