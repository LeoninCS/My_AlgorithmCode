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
    vector<int> dp(5005, inf);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 0;
    } 
    int g = a[0];
    for(int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == g) cnt++;
    }
    if(cnt > 0) {
        cout << n - cnt << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < 5005; j++) {
            int gg = __gcd(a[i], j);
            dp[gg] = min(dp[gg], dp[j] + 1);
        }
    }
    cout << dp[g] + n - 1 << "\n";
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