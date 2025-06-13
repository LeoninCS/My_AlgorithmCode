#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    bitset<200005> curr;
    bitset<200005> temp;
    curr.set(a[0]);
    int ans = 1;

    for(int i = 1; i < n; i++) {
        temp.set(a[i]);
        if ((curr & temp) == curr) {
            ans++;
            curr = temp;
            temp.reset();
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
