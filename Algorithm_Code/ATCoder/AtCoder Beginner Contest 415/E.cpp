#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<vector<i64>> v(h,vector<i64>(w, 0));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }
    vector<i64> p(h + w);
	for(int i = 1; i < h + w; i++) cin >> p[i];
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            v[i][j] -= p[i + j + 1];
        }
    }

    auto check = [&](i64 mid) -> bool {
        vector<vector<i64>> dp(h + 1, vector<i64>(w + 1, -1e18));
        dp[0][0] = mid;
        dp[1][0] = mid;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + v[i - 1][j - 1];
                //cout << dp[i][j] << " ";
                if(dp[i][j] < 0) dp[i][j] = -1e18;
            }
            //cout << "\n";
        }
        return dp[h][w] >= 0;
    };
    i64 l = 0, r = 1e18;
    while(l <= r) {
        i64 mid = l + (r - l) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
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