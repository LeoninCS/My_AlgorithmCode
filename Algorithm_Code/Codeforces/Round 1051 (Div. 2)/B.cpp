#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pii = pair<int,int>;
using Pll = pair<i64,i64>;


void solve()
{
	int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int nn = n;
    for(int i = 0; i < k; i++) {
        if(b[i] > nn) break;
        a[nn - b[i]] = 0;
        nn -= b[i];
    }
    i64 ans = 0;
    for(int i = 0; i < n; i++) ans += a[i];
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