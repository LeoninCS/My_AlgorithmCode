#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> vis(n, -1);
    vector<int> smalls, peaks;

    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i < n - 1; i++) {
        if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
            vis[i] = 0;
            smalls.push_back(i);
        } else if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            vis[i] = 1;
            peaks.push_back(i);
        }
    }

    i64 ans = 0;

    for (int i = 0; i < n - 1; i++) {
        if (v[i] >= v[i + 1]) continue;

        auto it0_1 = lower_bound(smalls.begin(), smalls.end(), i + 1);
        if (it0_1 == smalls.end()) continue;
        auto it0_2 = it0_1 + 1;

        auto it1_1 = lower_bound(peaks.begin(), peaks.end(), i + 1);
        if (it1_1 == peaks.end()) continue;
        auto it1_2 = it1_1 + 1;

        int p1 = *it0_1, p2 = *it1_1;
        int l = max(p1, p2);
        int r = n - 1;

        // 找第二个极小或极大的位置，作为右边界
        if (it0_2 != smalls.end()) r = min(r, *it0_2);
        if (it1_2 != peaks.end()) r = min(r, *it1_2);

        ans += r - l;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
