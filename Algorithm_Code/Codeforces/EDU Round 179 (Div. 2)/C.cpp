#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    i64 cnt = 0;
    i64 ans = 1e15;
    a.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[i + 1])  {
            cnt++;
            continue;
        }
        i64 res = a[i] * (n - cnt - 1);
        ans = min(ans, res);
        cnt = 0;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
