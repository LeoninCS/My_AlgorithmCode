#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    i64 cur = a[k - 1];
    sort(a.begin(),a.end());
    i64 t = 0;
    while(true) {
        //cout << cur << " " << t << "\n";
        i64 idx = upper_bound(a.begin(), a.end(), cur * 2 - t) - a.begin();
        i64 nxt = a[idx - 1];
        t += nxt - cur;
        if(nxt == cur) break;
        cur = nxt;
    }
    if(cur == a[n - 1]) cout << "YES\n";
    else cout << "NO\n";
    
    
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