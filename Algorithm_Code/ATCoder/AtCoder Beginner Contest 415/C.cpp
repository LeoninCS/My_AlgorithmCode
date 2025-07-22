#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n;
    string s;
    cin >> n >> s;
    vector<bool> dp((1 << n), false);
    dp[0] = true;
    for(int i = 0; i < (1 << n); i++) {
        if(dp[i] == false) continue;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) continue;
            if(s[i + (1 << j) - 1] == '1') continue;
            dp[i + (1 << j)] = true;
        }
    }
    if(dp[(1 << n) - 1]) cout << "Yes\n";
    else cout << "No\n";
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