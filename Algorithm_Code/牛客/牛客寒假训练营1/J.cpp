#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll cnt[2000010];
void solve() {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                int aj1 = x ^ j;
                if (aj1 != 0 && cnt[aj1] && gcd(x, aj1) == j) {
                    ans += cnt[aj1];
                }
                int k = x / j;
                if (k != j) {
                    int aj2 = x ^ k;
                    if (aj2 != 0 && cnt[aj2] && gcd(x, aj2) == k) {
                        ans += cnt[aj2];
                    }
                }
            }
        }
    }
    cout << ans / 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}