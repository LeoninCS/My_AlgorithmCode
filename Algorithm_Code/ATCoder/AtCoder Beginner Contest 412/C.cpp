#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int mi = s[0], mx = s[n - 1];
    sort(s.begin(), s.end());
    int ans = 2;
    while(mi * 2 < mx) {
        mi *= 2;
        int pos = upper_bound(s.begin(), s.end(), mi) - s.begin();
        pos--;
        if(s[pos] == mi / 2) {
            cout << -1 << "\n";
            return;
        }
        mi = s[pos];
        ans++;
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