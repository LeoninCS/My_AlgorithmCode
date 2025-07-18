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
    i64 mx = 0;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 1) cnt1++;
        else cnt2++;
        mx = max(mx, a[i]);
    }
    if(cnt1 && cnt2) {
        i64 ans = 1;
        for(int i = 0; i < n; i++) {
            ans += (a[i] / 2 * 2);
        }
        cout << ans << "\n";
    } else {
        cout << mx << "\n";
    }
    
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