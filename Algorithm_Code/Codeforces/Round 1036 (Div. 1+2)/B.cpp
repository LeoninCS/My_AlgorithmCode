#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<i64> dp(n + 1,0);
    i64 mi = 1e18;
    i64 ans = 1e18;
    for(int i = 1; i <= n; i++) {
        if(i < n){
            i64 cal = min(mi, a[i - 1] + a[i]);
            i64 cur = dp[i - 1] + cal;
            ans = min(ans, cur);
        } 
        mi = min(mi, a[i - 1]);
        dp[i] = dp[i - 1] + mi;
    }
    ans = min(ans, dp[n]);
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