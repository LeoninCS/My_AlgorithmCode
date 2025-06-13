#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    map<int, int> mpa, mpb;
    mpa[a[n - 1]] = n - 1;
    mpb[b[n - 1]] = n - 1;

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            ans = i + 1;
            break;
        }
        if (i + 1 < n && a[i] == a[i + 1]) {
            ans = i + 1;
            break;
        }
        if (i + 1 < n && b[i] == b[i + 1]) {
            ans = i + 1;
            break;
        }
        if (mpa.count(b[i]) && mpa[b[i]] - i > 1) {
            ans = i + 1;
            break;
        }
        if(mpa.count(a[i]) && mpa[a[i]] - i > 1) {
            ans = i + 1;
            break;
        }
        if (mpb.count(a[i]) && mpb[a[i]] - i > 1) {
            ans = i + 1;
            break;
        }
        if(mpb.count(b[i]) && mpb[b[i]] - i > 1) {
            ans = i + 1;
            break;
        }
        if(!mpa[a[i]]) mpa[a[i]] = i;
        if(!mpa[b[i]]) mpb[b[i]] = i;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}
