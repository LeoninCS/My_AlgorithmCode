//start:2025-9-13---09:51:00
//  end:2025-9-13---10:36:00
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    int vis[5001] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
        g = __gcd(g, a[i]);
    }
    int ans = 0;
    while(1) {
        if(vis[g]) break;
        for(int i = 0; i <= 5000; i++) {
            if(vis[i] == 0) continue;
            for(int j = 0; j < n; j++) {
                int gg = __gcd(i,a[j]);
                vis[gg] = 1;
            }
        }
        ans++;
    }
    if(ans) ans--;
    for(int i = 0; i < n; i++) {
        if(a[i] != g) ans++;
    }
    cout << ans << "\n";
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