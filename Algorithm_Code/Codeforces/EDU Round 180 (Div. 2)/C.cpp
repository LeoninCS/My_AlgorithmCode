#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;
const i64 INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
    int mx = -1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
        mx = max(mx, a[i]);
	} 
	sort(a.begin(),a.end());
    i64 ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            i64 l = upper_bound(a.begin() + j + 1,a.end(), mx - a[i] - a[j]) - a.begin();
            i64 r = lower_bound(a.begin() + j + 1,a.end(), a[i] + a[j]) - a.begin();
            r--;
            if(r < l) continue;
            ans += (r - l + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) solve();
	
	return 0;
}
