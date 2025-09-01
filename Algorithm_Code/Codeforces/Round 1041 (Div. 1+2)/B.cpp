#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
	int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int l = 1, r = 1;
    for(int i = x - 2; i >= 0; i--) {
        if(s[i] == '#') {
            l = i + 2;
            break;
        }
    }
    for(int i = x; i < n; i++) {
        if(s[i] == '#') {
            r = n - i + 1;
            break;
        }
    }
    int ans1 = min(l, n - x + 1);
    int ans2 = min(r, x);
    //cout << ans1 << " " << ans2 << "\n";
    int ans = max(ans1, ans2);
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