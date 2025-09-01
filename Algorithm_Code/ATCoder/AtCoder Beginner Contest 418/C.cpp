#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    while(q--) {
        long long b;
        cin >> b;
        int idx = lower_bound(a.begin(),a.end(),b) - a.begin();
        if(idx == n) {
            cout << -1 << "\n";
            continue;
        } 
        //cout << pre[idx] << "\n";
        long long ans = pre[idx] + ((n - idx) * (b - 1) + 1);
        cout << ans << "\n";
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