#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	i64 n,t,k;
	cin >> n >> t >> k;
	n -= k;
	n /= t;
	cout << min(n,k + 1) << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
