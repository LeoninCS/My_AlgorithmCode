#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	} 
    int ans = 1e9;
	for(int i = 0; i < n; i++) {
        int mx = -1, mi = 1e9;
        for(int j = i - 1; j >= 0; j--) {
            if(a[j] == a[i] - 1 || a[j] == a[i] || a[j] == a[i] + 1) {
                ans = min(ans, i - j - 1);
                break;
            }
            mx = max(mx, a[j]);
            mi = min(mi, a[j]);
            if(mx > a[i] && mi < a[i]) {
                ans = min(ans, i - j - 1);
                break;
            }
        }
        mx = -1, mi = 1e9;
        for(int j = i + 1; j < n; j++) {
            if(a[j] == a[i] - 1 || a[j] == a[i] || a[j] == a[i] + 1) {
                ans = min(ans, j - i - 1);
                break;
            }
            mx = max(mx, a[j]);
            mi = min(mi, a[j]);
            if(mx > a[i] && mi < a[i]) {
                ans = min(ans, j - i - 1);
                break;
            }
        }
    }
    if(ans == 1e9) cout << -1 << "\n";
    else cout << ans << "\n";
    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
