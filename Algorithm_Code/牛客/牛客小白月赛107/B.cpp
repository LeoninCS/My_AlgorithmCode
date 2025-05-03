#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_set<int> se;
    long long mx = 0,mi = INT_MAX;
	for (int i = 0; i < n; i++) {
        long long x = 0;
		cin >> x;
		mx = max(mx, x);
		mi = min(mi, x);    
    }
	long long mid = (mi + mx + 1) / 2;
	long long ans = (mid - mi) + (mx - mid);
    cout << ans << " " << mid << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	solve();
    return 0;
}

