#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
using PLL = pair<i64,i64>;


void solve()
{
	int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    i64 ans = 0;
    for(int i = n - 1; i >= max(n - m, 0); i--) {
        ans += a[i] * (m - (n - 1 - i));
        //cout << ans << " ";
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