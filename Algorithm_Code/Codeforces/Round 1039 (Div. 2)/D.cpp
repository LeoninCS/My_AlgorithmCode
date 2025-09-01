#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    if(a[1] > a[0]) dp[2] = 2;
    else dp[2] = 3;
    vector<int> len(n + 1, 0);
    len[1] = 1;
    if(a[1] > a[0]) len[2] = 1;
    else len[2] = 2;
    for(int i = 3; i <= n; i++) {
        len[i] = max(len[i - 1], len[i - 2]) + 1;
        if(a[i - 1] > a[ i - 2]) {
            dp[i] = dp[i - 1] + 1;

        } else {
            if(a[i - 2] < a[i - 3]) {
                dp[i] = dp[i - 1] + len[i];
            } else {
                dp[i] = dp[i - 1] + len[i - 1] + len[i - 2];
            }
        }
        //cout << dp[i] << " ";
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i];
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