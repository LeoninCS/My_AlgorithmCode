#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct st {
    int val, l, r;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> idx(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= n) {
            idx[a[i]].push_back(i);
        }
    }

    vector<st> v;

    for (int val = 1; val <= n; val++) {
        if (idx[val].size() >= val) {
            for (size_t i = 0; i + val - 1 < idx[val].size(); i++) {
                int l = idx[val][i];
                int r = idx[val][i + val - 1];
                v.push_back({val, l, r});
            }
        }
    }

    sort(v.begin(), v.end(), [](const st &x, const st &y) {
        return x.r < y.r;
    });

    vector<int> dp(n + 1, 0);

    int bl = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];

        while (bl < v.size() && v[bl].r == i) {
            int l = v[bl].l;
            int val = v[bl].val;

            int prev_dp_val = (l > 0) ? dp[l] : 0;
            dp[i + 1] = max(dp[i + 1], prev_dp_val + val);

            bl++;
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}