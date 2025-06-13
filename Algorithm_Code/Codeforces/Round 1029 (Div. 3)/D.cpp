#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    i64 A = a[0], B = a[n - 1];

    i64 denom = 1 - 1LL * n * n;
    i64 numerator_y = B - n * A;

    if (denom == 0) {
        cout << "NO\n";
        return;
    }

    if (numerator_y % denom != 0) {
        cout << "NO\n";
        return;
    }

    i64 y = numerator_y / denom;
    i64 x = A - n * y;
    if(x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != x * (i + 1) + y * (n - i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
